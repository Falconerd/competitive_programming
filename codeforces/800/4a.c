#include <stdio.h>

int main(void) {
    int w;
    scanf("%d", &w);

    if (w % 2 == 0 && w > 3) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}
