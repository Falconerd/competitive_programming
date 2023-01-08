#include <stdio.h>
#include <string.h>

int main(void) {
    int test_case_count;
    scanf("%d", &test_case_count);

    for (int i = 0; i < test_case_count; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if (a == b + c || b == a + c || c == a + b) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}

