/*
ID: me85
LANG: C
TASK: paint
*/
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return b > a ? b : a;
}

int min(int a, int b) {
    return b < a ? b : a;
}

int main() {
    FILE *fin = fopen("paint.in", "r");
    FILE *fout = fopen("paint.out", "w");

    int a, b, c, d;
    int result;

    fscanf(fin, "%d %d", &a, &b);
    fscanf(fin, "%d %d", &c, &d);

    if (b < c || a > d) {
        result = b - a + d - c;
    } else {
        result = max(b, d) - min(a, c);
    }

    fprintf(fout, "%d\n", result);

    exit(0);
}
