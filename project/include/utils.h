#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_

#include <stdio.h>
#include "data.h"

void masterWrite(FILE * restrict ofPTR, Data Client);

void blackRecord(FILE * restrict ofPTR, FILE * restrict ofPTR_2,
                 FILE * restrict blackrecord, Data client_data, Data transfer);

void transactionWrite(FILE * restrict ofPtr, Data transfer);

#endif  // PROJECT_INCLUDE_UTILS_H_
