#include <stdio.h>

int main(void) {
    int count;
    scanf("%d", &count);

    int result = 0;

    for (int i = 0; i < count; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        result += a + b + c > 1;
    }

    printf("%d\n", result);

    return 0;
}

