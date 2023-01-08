/*
ID: me85
LANG: C
TASK: speeding
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fin = fopen("speeding.in", "r");
    FILE *fout = fopen("speeding.out", "w");

    int n, m;
    int p = 0;

    fscanf(fin, "%d %d", &n, &m);

    //  0 - 40 : 70
    // 40 - 90 : 35
    // 90 - 99 : 45
    //
    //  0 - 40 : 76
    // 40 - 60 : 30
    // 60 - 99 : 40

    // road:  [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ]
    // limit: [ 70 ->       35 ->          45 -> ]
    // speed: [ 76 ->       30 -> 40 ->          ]
    //
    // for each speed segment
    //      if overlapping with any limit segment
    //          if limit < speed
    //              if speed - limit > largest
    //                  largest = speed - limit
    //
    // store limits in array (got idea from peeking... should stop doing that)
    // index: [ 0, 1, 2, ... 40, 41, 42, ... 90, 91, ... ]
    // value: [ 70, 70, ..., 35, 35, 35, ... 45, 45, ... ]
    //
    // then when checking the driving segments, get the speed limit from limits.
    // this is most likely why the road is only 100 miles in the story.
    int limits[100];

    for (int i = 0; i < n; ++i) {
        int length, limit;
        fscanf(fin, "%d %d", &length, &limit);

        for (int j = p; j < p + length; ++j) {
            limits[j] = limit;
        }

        p += length;
    }

    int max = 0;
    p = 0;

    for (int i = 0; i < m; ++i) {
        int length, speed;
        fscanf(fin, "%d %d", &length, &speed);

        for (int j = p; j < p + length; ++j) {
            if (speed > limits[j]) {
                if (speed - limits[j] > max) {
                    max = speed - limits[j];
                }
            }
        }

        p += length;
    }

    fprintf(fout, "%d\n", max);

    exit(0);
}

