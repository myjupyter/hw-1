#include <stdlib.h>

#include "tests.h"


int main(int argc, char** argv) {
    if (argc < 2) {
        printf("There should be more parameters!");
    }
    switch(atoi(argv[1])) {
        case 1:
        test_masterWrite();
        printf("\n__________________________#1 Test \"masterWrite()\" has been passed...__________________________\n");
        break;
        case 2:
        test_transactionWrite();
        printf("\n__________________________#2 Test \"transactionWrite()\" has been passed...__________________________\n");
        break;
        case 3:
        test_blackRecord();
        printf("\n__________________________#3 Test \"blackRecord()\" has been passed...__________________________\n");
        break;
        default:
        printf("You could choose only 1-2-3 tests!");
        break;
    }
    return 0;    
}
