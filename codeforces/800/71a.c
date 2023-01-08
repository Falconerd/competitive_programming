#include <stdio.h>
#include <string.h>

int main(void) {
    int word_count;
    scanf("%d", &word_count);

    for (int i = 0; i < word_count; ++i) {
        char string[100];

        scanf("%s", string);

        int length = strlen(string);
        if (length > 10) {
            printf("%c%d%c\n", string[0], length - 2, string[length - 1]);
        } else {
            printf("%s\n", string);
        }
    }

    return 0;
}
