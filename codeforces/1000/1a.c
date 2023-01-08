#include <stdio.h>
#include <math.h>

int main(void) {
    double n, m, a;
    scanf("%lf %lf %lf", &n, &m, &a);

    long long columns = 1;
    long long rows = 1;

    if (a < n) {
        columns = (long long)ceil(n / a);
    }

    if (a < m) {
        rows = (long long)ceil(m / a);
    }

    long long result = columns * rows;

    printf("%lld\n", result);

    return 0;
}

