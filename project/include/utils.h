#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_

#include <stdio.h>
#include "data.h"

void masterWrite(FILE *ofPTR, Data Client);

void blackRecord(FILE *ofPTR, FILE *ofPTR_2, FILE *blackrecord,
                 Data client_data, Data transfer);

void transactionWrite(FILE *ofPtr, Data transfer);

#endif  // PROJECT_INCLUDE_UTILS_H_
