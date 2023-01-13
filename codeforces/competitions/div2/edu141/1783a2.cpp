#include <iostream>
#include <vector>
using namespace std;

bool isUgly(vector<int>& a) {
    int n = a.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum == a[i]) {
            return true;
        }
        sum += a[i];
    }

    return false;
}

void reorder(vector<int>& a) {
    int n = a.size();
    if (n <= 2) {
        return;
    }
    int i = n - 1, j = n - 2;
    while (i > 0 && j >= 0) {
        if (a[j] >= a[i]) {
            j--;
        } else {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i--;
            j--;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (isUgly(a)) {
            reorder(a);
            if (isUgly(a)) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
                for (int i = 0; i < n; i++) {
                    cout << a[i] << " ";
                }
                cout << endl;
            }
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

