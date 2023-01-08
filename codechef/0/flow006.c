#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int count;
    scanf("%d", &count);

    for (int i = 0; i < count; ++i) {
        char string[8] = {0};
        scanf("%s", string);

        int sum = 0;
        int string_length = strlen(string);

        for (int j = 0; j < string_length; ++j) {
            char c[] = {string[j], 0};
            sum += atoi(c);
        }

        printf("%d\n", sum);
    }

    return 0;
}
