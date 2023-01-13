#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;

    // long/tall single row/col
    if (n == 1 || m == 1) {
        cout << "1 1" << endl;
        return;
    }

    // square <= 3x3
    if (n == m && n <= 3) {
        cout << "2 2" << endl;
        return;
    }

    // long/tall double row/col can move anywhere if larger side is > 3
    if ((n >= 2 && m > 3) || (m >= 2 && n > 3)) {
        cout << "1 1" << endl;
        return;
    }

    for (int y = 0; y < m; ++y) {
        for (int x = 0; x < n; ++x) {
            int dl = x;
            int dr = n - x - 1;
            int dt = m - y - 1;
            int db = y;

            if (n > m) {
                if ((dl == 1 && dr == 1) && dt + db == 1) {
                    cout << x + 1 << " " << y + 1 << endl;
                    return;
                }
            } else if (m > n) {
                if ((dt == 1 && db == 1) && dl + dr == 1) {
                    cout << x + 1 << " " << y + 1 << endl;
                    return;
                }
            }
        }
    }
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

