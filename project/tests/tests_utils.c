#include "tests_utils.h"

void read_from_trans_file(const char * filename, Data * data) {
    FILE * fromFile = fopen(filename, "r");
    assert(fromFile != NULL); 

    if (fscanf(fromFile,"%d %lf", &data->Number, &data->cash_payments) == -1) {
        fprintf(stderr, "read_from_file: attempt to read from %s file!!! It's empty!!!\n", filename);
    }

    fclose(fromFile); 
}

void read_from_file(const char * filename, Data * data) {
    FILE * fromFile = fopen(filename, "r");
    assert(fromFile != NULL);

    if (fscanf(fromFile,"%d%19s%19s%29s%14s%lf%lf%lf", &data->Number, data->Name,
               data->Surname, data->addres, data->TelNumber, &data->indebtedness,
               &data->credit_limit, &data->cash_payments) == -1) {
        fprintf(stderr, "read_from_file: attempt to read from %s file!!! It's empty!!!\n", filename);
    }

    fclose(fromFile);
}

int compare_data(Data * const data, Data * const data_2) {
    if (data->Number == data_2->Number &&
        data->indebtedness == data_2->indebtedness &&
        data->credit_limit == data_2->credit_limit &&
        data->cash_payments == data_2->cash_payments &&
        !strncmp(data->Name, data_2->Name, NAME_SIZE) &&
        !strncmp(data->Surname, data_2->Surname, SURNAME_SIZE) &&
        !strncmp(data->addres, data_2->addres, ADDRESS_SIZE) &&
        !strncmp(data->TelNumber, data_2->TelNumber, TELNUMBER_SIZE)) {
        return EQ;
    }
    return NOT_EQ;
}

