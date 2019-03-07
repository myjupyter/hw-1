#include <stdlib.h>
#include <stdio.h>

#include "utils.h"
#include "module.h"

#define ERR_ARGS_COUNT (-1)
#define ERR_WRONG_FLG (-2)

#define TST_FOO_FIX     1
#define TST_FOO_IMPL    2
#define TST_MOD_IMPL    3


/* NOTE(stitaevskiy):
 * We use `atoi` function just for simplification and code reducing.
 * This function doesn't report conversation errors.
 * For safety program we recommend using `strtol` and its analogs.
 * (See `man atoi` and `man strtol` for more info).
 *
 * const char str_num[] = "1234";
 * char* end = NULL;
 * int val = (int) strtol(str_num, &end, 0);
 * if (end != '\0') {
 *     //ERROR
 * }
 *
 * */

int main(int argc, const char** argv) {
    if (argc < 3) {
        return ERR_ARGS_COUNT;
    }

    const char* data = argv[2];
	char* end = NULL;
    int test_case = (int) strtol(argv[1], &end, 0);

    switch (test_case) {
        case TST_FOO_FIX: {
            printf("%zu\n", custom_strlen(data));
            break;
        }
        case TST_FOO_IMPL: {
            if (argc != 4) {
                return ERR_ARGS_COUNT;
            }
    
			int base = atoi(data);
            int pow = atoi(argv[3]);
            int res = custom_pow(base, pow);

            printf("%i\n", res);
            break;
        }
        case TST_MOD_IMPL: {
            int num = atoi(data);

            printf("%i\n", is_prime(num));
			break;
        }
        default: {
            return ERR_WRONG_FLG;
        }
    }

    return 0;
}
