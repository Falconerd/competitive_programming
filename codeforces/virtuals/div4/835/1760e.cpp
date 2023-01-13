#include <bits/stdc++.h>
#include <climits>
#include <iostream>
using namespace std;

int count_inversions(int n, int *arr) {
    int count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (arr[i] && !arr[j]) {
                ++count;
            }
        }
    }

    return count;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int n;
        cin >> n;

        int arr[n];
        int arr2[n];

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            arr2[i] = arr[i];
        }

        int max = count_inversions(n, arr);

        for (int i = 0; i < n; ++i) {
            arr[i] = !arr[i];
            int count = count_inversions(n, arr);
            if (count > max) {
                max = count;
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            arr2[i] = !arr2[i];
            int count = count_inversions(n, arr2);
            if (count > max) {
                max = count;
            }
        }

        cout << max << endl;
    }
}
