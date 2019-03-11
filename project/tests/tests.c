#include "tests.h"

void test_masterWrite() {
    FILE * Ptr = fopen(RECORD, "w");
    Data record_value = {0, "", "", "", "", 0.0, 0.0, 0.0};
    
    assert(Ptr != NULL);
    masterWrite(Ptr, record_value);
    
    fclose(Ptr);
    
    Data test_value = {0, "", "", "", "", 0.0, 0.0, 0.0};
    read_from_file("test_record.dat", &test_value);
    read_from_file(RECORD, &record_value);

    assert(compare_data(&test_value, &record_value) == 1);
}

void test_transactionWrite() {
    FILE * Ptr = fopen(TRANSACTION, "w");
    Data transaction_value = {0, "", "", "", "", 0.0, 0.0, 0.0};
    
    assert(Ptr != NULL);
    transactionWrite(Ptr, transaction_value);

    fclose(Ptr);
    
    Data test_value = {0, "", "", "", "", 0.0, 0.0, 0.0};
    read_from_trans_file("test_transaction.dat", &test_value);
    read_from_trans_file(TRANSACTION, &transaction_value);

    assert(compare_data(&test_value, &transaction_value) == 1);
}

void test_blackRecord() {
    FILE * Ptr = fopen("test_record.dat", "r");
    FILE * Ptr_2 = fopen("test_transaction.dat", "r");
    FILE * Ptr_3 = fopen(BLACKRECORD, "w");

    Data test_value = {0, "", "", "", "", 0.0, 0.0, 0.0};
    Data blackrecord_value = {0, "", "", "", "", 0.0, 0.0, 0.0};

    assert(Ptr != NULL);
    assert(Ptr_2 != NULL);
    assert(Ptr_3 != NULL);

    blackRecord(Ptr, Ptr_2, Ptr_3, test_value, blackrecord_value);
 
    fclose(Ptr);
    fclose(Ptr_2);
    fclose(Ptr_3);

    read_from_file("test_blackrecord.dat", &test_value);
    read_from_file(BLACKRECORD, &blackrecord_value);

    assert(compare_data(&test_value, &blackrecord_value) == 1);
}
