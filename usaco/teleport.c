/*
ID: me85
LANG: C
TASK: teleport
*/
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return b > a ? b : a;
}

int min(int a, int b) {
    return b < a ? b : a;
}

/*

   3 - 2 = 1
   10 - 8 = 2
   = 3

   10 - 3 = 7

   3 < 7 


*/

int main() {
    FILE *fin = fopen("teleport.in", "r");
    FILE *fout = fopen("teleport.out", "w");

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

