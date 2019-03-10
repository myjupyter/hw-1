CC = gcc
TARGET = main.out
CFLAGS = -Wall -Wextra -Werror -I 
LDFLAGS = 
HDRS_DIR = project/include
DATA_FILES = record.dat blackrecord.dat transaction.dat

SRCS = \
       project/src/main.c \
       project/src/utils.c \

.PHONY: all clean

all: $(SRCS)
	$(CC) $(CFLAGS) $(HDRS_DIR) -o $(TARGET) $(SRCS)
data:
	touch $(DATA_FILES)
clean:
	rm -rf $(TARGET) $(DATA_FILES)
