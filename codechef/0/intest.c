#include <stdio.h>

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    int count = 0;

    for (int i = 0; i < n; ++i) {
        int m;
        scanf("%d", &m);
        count += m % k == 0;
    }

    printf("%d\n", count);

    return 0;
}

