#include <stdio.h>
#include <string.h>

int main(void) {
    int count;
    scanf("%d", &count);

    for (int i = 0; i < count; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);

        if (a > b) {
            printf(">\n");
        } else if (a < b) {
            printf("<\n");
        } else {
            printf("=\n");
        }
    }

    return 0;
}
