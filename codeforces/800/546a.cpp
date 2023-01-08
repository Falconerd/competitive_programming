#include <cstdio>
#include <string>
using namespace std;

int main(void) {
    int k, n, w;

    scanf("%d %d %d\n", &k, &n, &w);

    int cost = 0;

    for (int i = 1; i <= w; ++i) {
        cost += i * k;
    }

    printf("%d\n", cost > n ? cost - n : 0);
}
