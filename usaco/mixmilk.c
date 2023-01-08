/*
ID: me85
LANG: C
TASK: mixmilk
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fin = fopen("mixmilk.in", "r");
    FILE *fout = fopen("mixmilk.out", "w");

    int c[3];
    int m[3];

    for (int i = 0; i < 3; ++i) {
        fscanf(fin, "%d %d", &c[i], &m[i]);
    }

    int b1 = 0;
    int b2 = 1;
    for (int i = 0; i < 100; ++i) {
        int milk_to_pour = m[b1];
        int space_left = c[b2] - m[b2];

        if (milk_to_pour > space_left) {
            // Pour remainder.
            m[b1] -= space_left;
            m[b2] = c[b2];
        } else {
            m[b1] = 0;
            m[b2] += milk_to_pour;
        }

        b1 = (b1 + 1) % 3;
        b2 = (b2 + 1) % 3;
    }

    for (int i = 0; i < 3; ++i) {
        fprintf(fout, "%d\n", m[i]);
    }

    exit(0);
}
