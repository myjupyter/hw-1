#include "utils.h"

#define MAIN_MENU   "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n"
#define TRANSACTION "transaction.dat"
#define RECORD      "record.dat"
#define BLACKRECORD "blackrecord.dat"

int main(void) {
    FILE *Ptr = NULL;
    FILE *Ptr_2 = NULL;
    FILE *Ptr_3 = NULL;
    Data client_data = {0, " ", " ", " ", " ", 0.0, 0.0, 0.0};
    Data transfer = {0, " ", " ", " ", " ", 0.0, 0.0, 0.0};

    printf("%s", MAIN_MENU);

    int choice = 0;

    while (scanf("%d", &choice) != -1) {
        switch (choice) {
            case 1:
                Ptr = fopen(RECORD, "r+");
                if (Ptr == NULL) {
                    puts("Not acess");
                } else {
                    masterWrite(Ptr, client_data);
                    fclose(Ptr);
                }
                break;
            case 2:
                Ptr = fopen(TRANSACTION, "r+");
                if (Ptr == NULL) {
                    puts("Not acess");
                } else {
                    transactionWrite(Ptr, transfer);
                    fclose(Ptr);
                }
                break;
            case 3:
                Ptr = fopen(RECORD, "r");
                Ptr_2 = fopen(TRANSACTION, "r");
                Ptr_3 = fopen(BLACKRECORD, "w");

                if (Ptr == NULL || Ptr_2 == NULL || Ptr_3 == NULL) {
                    puts("exit");
                } else {
                    blackRecord(Ptr, Ptr_2, Ptr_3, client_data, transfer);
                    fclose(Ptr);
                    fclose(Ptr_2);
                    fclose(Ptr_3);
                }
                break;
            default:
                puts("error");
                break;
        }
        printf("%s", MAIN_MENU);
    }
    return 0;
}
