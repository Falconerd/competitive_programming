#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
    }
    cout << (10 - n) * (3 * (10 - n - 1)) << endl;
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

