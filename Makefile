CC = gcc
TARGET = main.out
CFLAGS = -Wall -Wextra -Werror -I 
LDFLAGS = 
HDRS_DIR = project/include
DATA_FILES = record.dat blackrecord.dat transaction.dat
TEST_FILES = test_record.dat test_blackrecord.dat test_transaction.dat

MAIN_SRCS = project/src/main.c

SRCS = \
       project/src/utils.c \
       project/src/program.c \

TEST_SRCS = \
            project/tests/main_tests.c \
            project/tests/tests_utils.c \
            project/tests/tests.c \

.PHONY: all clean

all: $(SRCS)
	$(CC) $(CFLAGS) $(HDRS_DIR) -o $(TARGET) $(MAIN_SRCS) $(SRCS)
data:
	touch $(DATA_FILES)
test:
	touch $(TEST_FILES)
	echo "0 UserName Surname UserAddress UserTelNum 20.0 20.0 50.0" > test_record.dat
	echo "0  23.0" > test_transaction.dat
	echo "0 UserName Surname UserAddress UserTelNum 20.0 43.0 50.0" > test_blackrecord.dat
	$(CC) $(CFLAGS) $(HDRS_DIR) -o test.out $(TEST_SRCS) $(SRCS)
	./test.out 1 < test_record.dat
	./test.out 2 < test_transaction.dat
	./test.out 3 < test_blackrecord.dat
clean:
	rm -rf test.out $(TARGET) $(DATA_FILES) $(TEST_FILES)
