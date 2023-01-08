#include <stdio.h>

char *binary_add (unsigned a, unsigned b, char *binary)
{
    unsigned long sum = (unsigned long)a + (unsigned long)b;
    int bit_count = sizeof(unsigned long) * 8;
    unsigned long mask = 1;

    if (sum == 0) {
        binary[0] = '0';
        binary[1] = 0;
        return binary;
    }

    mask <<= bit_count - 1;

    int leading_zero_count = 0;

    while ((sum & mask) == 0 && leading_zero_count < bit_count) {
        mask >>= 1;
        leading_zero_count += 1;
    }

    int len = bit_count - leading_zero_count;

    for (int i = 0; i < len; ++i) {
        binary[i] = ((sum & mask) > 0) + '0';
        mask >>= 1;
    }

    binary[len] = 0;

	return binary;
}
