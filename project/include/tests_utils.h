#ifndef PROJECT_INCLUDE_TESTS_UTILS_H_
#define PROJECT_INCLUDE_TESTS_UTILS_H_

#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "data.h"

#define EQ 1
#define NOT_EQ 0

void read_from_trans_file(const char * filename, Data * data);

void read_from_file(const char * filename, Data * data);

int compare_data(Data * const data, Data * const data_2);

#endif  // PROJECT_INCLUDE_TESTS_UTILS_H_

