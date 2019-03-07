#define PRIME 1
#define NOT_PRIME 0

// TODO(jupiter): Checks whether a number is prime
int is_prime(int number) {
	if(number <= 1) {
    	return NOT_PRIME;
	}
    for (int i = 2; i * i <= number; ++i) {
		if(number % i == 0) {
			return NOT_PRIME;
		}
		return PRIME;
	}
	return PRIME;
}
