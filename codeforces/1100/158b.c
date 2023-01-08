#include <stdio.h>

int main(void) {
    int count;
    scanf("%d", &count);

    int taxi_count = 0;

    // ignore index 0, don't need index 4 as that's a full taxi.
    int group_sizes[4] = {0};

    for (int i = 0; i < count; ++i) {
        int group_size;
        scanf("%d", &group_size);

        if (group_size == 4) {
            taxi_count += 1;
        } else {
            group_sizes[group_size] += 1;
        }
    }

    while (group_sizes[1] + group_sizes[2] + group_sizes[3] > 0) {
        // Greedily use all threes.
        while (group_sizes[3] > 0) {
            if (group_sizes[1] > 0) {
                group_sizes[1] -= 1;
            }

            group_sizes[3] -= 1;
            taxi_count += 1;
        }

        // Greedily use all twos.
        while (group_sizes[2] > 0) {
            if (group_sizes[2] >= 2) {
                group_sizes[2] -= 1;
            } else if (group_sizes[1] >= 2) {
                group_sizes[1] -= 2;
            } else if (group_sizes[1] == 1) {
                group_sizes[1] = 0;
            }

            group_sizes[2] -= 1;
            taxi_count += 1;
        }

        // Greedily use all ones.
        while (group_sizes[1] > 0) {
            if (group_sizes[1] >= 4) {
                group_sizes[1] -= 4;
            } else {
                group_sizes[1] = 0;
            }

            taxi_count += 1;
        }
    }

    printf("%d\n", taxi_count);

    return 0;
}
