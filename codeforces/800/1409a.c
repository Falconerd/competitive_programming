#include <stdio.h>

int main(void) {
    int count;
    scanf("%d", &count);

    for (int i = 0; i < count; ++i) {
        long long a, b;
        scanf("%lld %lld", &a, &b);

        if (a > b) {
            a = a ^ b;
            b = a ^ b;
            a = a ^ b;
        }

        int moves = 0;
        while (a != b) {
            if (a + 10 <= b) {
                long long moves_to_get_close = (b - a) / 10;

                moves += moves_to_get_close;
                a += moves_to_get_close * 10;
            } else {
                ++moves;
                a = b;
            }
        }

        printf("%d\n", moves);
    }

    return 0;
}

