#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int test_cases;
    scanf("%d", &test_cases);

    for (int i = 0; i < test_cases; ++i) {
        int length, rotate_by;
        scanf("%d %d", &length, &rotate_by);

        // Don't these usually require no malloc?
        int *array = malloc(length * sizeof(int));

        // How slow is this?
        for (int j = 0; j < length; ++j) {
            scanf("%d", &array[(j + rotate_by) % length]);
        }

        for (int j = 0; j < length - 1; ++j) {
            printf("%d ", array[j]);
        }

        printf("%d\n", array[length - 1]);

        free(array);
    }
}
