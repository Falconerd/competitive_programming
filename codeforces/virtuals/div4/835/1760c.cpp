#include <bits/stdc++.h>
#include <climits>
#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int n;
        cin >> n;
        long long nums[n];
        long long largest = LONG_LONG_MIN;
        long long second_largest = LONG_LONG_MIN;
        long long sum = 0;

        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
            if (nums[i] > largest) {
                if (largest > LONG_LONG_MIN) {
                    second_largest = largest;
                }
                largest = nums[i];
            } else if (nums[i] > second_largest) {
                second_largest = nums[i];
            }

            sum += nums[i];
        }

        if (largest == n && sum == n * n) {
            for (int i = 0; i < n; ++i) {
                cout << "0 ";
            }
        } else {
            for (int i = 0; i < n; ++i) {
                if (nums[i] == largest) {
                    cout << nums[i] - second_largest << " ";
                } else {
                    cout << nums[i] - largest << " ";
                }
            }
        }

        cout << endl;
    }
}


