/*
ID: me85
LANG: C
TASK: beads
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char determine_bead_color(char beads[1050], int index, int direction) {
    char bead = beads[index];

    while (bead == 'w') {
        index += direction;
        bead = beads[index];
    }

    return bead;
}

int determine_segment_length(char beads[1050], char beads_counted[350], int bead_count, int index, char color, int direction) {
    return 0;
}

int main() {
    FILE *fin = fopen("beads.in", "r");
    FILE *fout = fopen("beads.out", "w");

    int bead_count;
    // Store three copies of the beads.
    // Use index bead_count as 0 and don't worry about wrapping.
    char beads[1050] = {0};
    char beads_counted[350] = {0};
    int largest = 0;

    fscanf(fin, "%d", &bead_count);
    fscanf(fin, "%s", beads);

    // Copy the beads.
    for (int i = 0; i < bead_count; ++i) {
        beads[bead_count + i] = beads[i];
        beads[bead_count * 2 + i] = beads[i];
    }

    printf("beads: %s\n", beads);
    printf("bead_count: %d\n", bead_count);
    printf("beads[bead_count] = %c\n", beads[bead_count]);
    printf("beads[bead_count * 2] = %c\n", beads[bead_count * 2]);

    for (int i = bead_count; i < bead_count + bead_count; ++i) {
        int left_index = i;
        int right_index = i + 1;

        char left_color = determine_bead_color(beads, left_index, -1);
        char right_color = determine_bead_color(beads, right_index, 1);

        int left_length = determine_segment_length(beads, beads_counted, bead_count, left_index, left_color, -1);
        int right_length = determine_segment_length(beads, beads_counted, bead_count, right_index, right_color, 1);

        if (largest < left_length + right_length) {
            largest = left_length + right_length;
        }

        memset(beads_counted, 0, 350);
    }

    fprintf(fout, "%d\n", largest);

    exit(0);
}

