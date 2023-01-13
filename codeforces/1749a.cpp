#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

void solve() {
    int n, c;
    cin >> n >> c;

    // store counts in first
    int rows[n];
    int cols[n];

    for (int i = 0; i < n; ++i) {
        rows[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        cols[i] = 0;
    }

    int max_row = 0;
    int max_col = 0;
    int zero_rows = n;
    int zero_cols = n;

    while (c--) {
        int row, col;
        cin >> row >> col;

        rows[row - 1]++;
        cols[col - 1]++;

        if (rows[row - 1] == 1) zero_rows--;
        if (cols[col - 1] == 1) zero_cols--;

        if (rows[row - 1] > max_row) max_row = rows[row - 1];
        if (cols[col - 1] > max_col) max_col = cols[col - 1];

        if (max_row >= 2 && max_col >= 2) {
            cout << "NO" << endl;
            return;
        }
    }

    if (zero_rows == 0 && zero_cols == 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll test_count;
    cin >> test_count;

    while (test_count--) {
        solve();
    }

    return 0;
}

