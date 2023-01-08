#include <stdio.h>
#include <string.h>

int main(void) {
    int count;
    scanf("%d", &count);

    for (int i = 0; i < count; ++i) {
        char string[8] = {0};
        scanf("%s", string);

        int length = strlen(string);

        for (int j = length - 1; j >= 0; --j) {
            printf("%c", string[j]);
        }

        printf("\n");
    }

    return 0;
}

