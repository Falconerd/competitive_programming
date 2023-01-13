/*
ID: me85
TASK: cowsignal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// XXX.
// X..X
// XXX.
// X..X
// XXX.

int main(void) {
    ofstream fout ("cowsignal.out");
    ifstream fin ("cowsignal.in");

    int m, n, k;
    fin >> m >> n >> k;

    for (int i = 0; i < m; ++i) {
        string s;
        fin >> s;
        for (int r = 0; r < k; ++r) {
            for (int j = 0; j < n; ++j) {
                fout << s[j % n] << s[j % n];
            }
            fout << endl;
        }
    }

    return 0;
}
