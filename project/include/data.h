#ifndef PROJECT_INCLUDE_DATA_H_
#define PROJECT_INCLUDE_DATA_H_

#define NAME_SIZE 20
#define SURNAME_SIZE 20
#define ADDRESS_SIZE 30
#define TELNUMBER_SIZE 15

typedef struct masterRecord {
    int Number;
    char Name[NAME_SIZE];
    char Surname[SURNAME_SIZE];
    char addres[ADDRESS_SIZE];
    char TelNumber[TELNUMBER_SIZE];
    double indebtedness;
    double credit_limit;
    double cash_payments;
} Data;

#endif  // PROJECT_INCLUDE_DATA_H_
