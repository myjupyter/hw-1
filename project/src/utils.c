#include <string.h>

#include "utils.h"

// TODO(jupiter): Returns size of str
size_t custom_strlen(const char* str) {
    return strlen(str);
}

// TODO(jupiter): Implement `power of` function
int custom_pow(int base, int power) {
	int result = 1;
	int base_to_the_power_2 = base;
	while(power > 0) {
		if((power & 1) == 1) {
			result *= base_to_the_power_2;
		}
		base_to_the_power_2 *= base_to_the_power_2;
		power = power >> 1;
	}
	return result;
}
