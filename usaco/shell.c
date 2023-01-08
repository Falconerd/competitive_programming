/*
ID: me85
LANG: C
TASK: shell
*/
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return b > a ? b : a;
}

// Revised version after peeking at their (usaco.guide) C++ solution.
int main() {
    FILE *fin = fopen("shell.in", "r");
    FILE *fout = fopen("shell.out", "w");

    int n;
    fscanf(fin, "%d", &n);

    int shells[3] = {0, 1, 2};
    int scores[3] = {0};

    for (int i = 0; i < n; ++i) {
        int a, b, g;
        fscanf(fin, "%d %d %d", &a, &b, &g);
        // Decrease to 0-index.
        --a; --b; --g;

        // Simulate swapping the shells.
        shells[a] = shells[a] ^ shells[b];
        shells[b] = shells[a] ^ shells[b];
        shells[a] = shells[a] ^ shells[b];
        // Could also use tmp var.
        //int tmp = shells[a];
        //shells[a] = shells[b];
        //shells[b] = tmp;

        ++scores[shells[g]];
    }

    fprintf(fout, "%d\n", max(max(scores[0], scores[1]), scores[2]));

    exit(0);
}

// Original solution by me.
// It's not actually simulation because the swaps aren't simulated.
// (this exercise was part of usaco.guide chapter on simulation)
//int main() {
//    FILE *fin = fopen("shell.in", "r");
//    FILE *fout = fopen("shell.out", "w");
//
//    int n;
//    fscanf(fin, "%d", &n);
//
//    int high_score = 0;
//
//    // For each starting position.
//    for (int i = 1; i <= 3; ++i) {
//        // Calculate what the score would have been.
//        // Pebble starts at i.
//        int p = i;
//        int score = 0;
//        for (int j = 0; j < n; ++j) {
//            int a, b, g;
//            fscanf(fin, "%d %d %d", &a, &b, &g);
//            
//            // Calculate score...
//            if (p == a) {
//                p = b;
//            } else if (p == b) {
//                p = a;
//            }
//
//            if (g == p) {
//                ++score;
//            }
//
//            if (score > high_score) {
//                high_score = score;
//            }
//        }
//    }
//
//    fprintf(fout, "%d\n", high_score);
//
//    exit(0);
//}
//
