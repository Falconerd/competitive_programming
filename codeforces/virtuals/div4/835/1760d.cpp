#include <bits/stdc++.h>
#include <climits>
#include <iostream>
using namespace std;

// 3 2 2 1 2 2 3
//   +         -> in valley whole time
//   so valleys should be 1
// 9 4 4 5 9 4 9 10
// ^ . .   ^ .   ^
// > < = > > < > >
//
// 1 2 3 4 3 2 1
//   + ^ 
//
// valleys = 0
// in_valley = false
// n = 1 -- start at index 1 since we already account for arrays of length 1
// if a[n] <= a[n - 1] and not in_valley then -- started a valley
//   valleys += 1
//   if (valleys == 1) then
//     return "NO"
//   end
//   in_valley = true
// end
// if a[n] > a[n - 1] then -- finished a valley
//   in_valley = false
// end
// if valleys == 1 then
//   return "YES"
// else
//   return "NO"
//

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int n;
        cin >> n;

        long long arr[n];
        // Maybe store peaks, use DP? not sure yet
        //

        if (n == 1) {
            cin >> arr[0];
            cout << "YES" << endl;
            continue;
        }

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        long long valleys = 1;
        bool in_valley = true;
        bool started_incline = false;

        for (int i = 1; i < n; ++i) {
            if (arr[i] <= arr[i - 1] && !in_valley) {
                started_incline = false;
                in_valley = true;
                ++valleys;

                if (valleys > 1) {
                    break;
                }
            }

            if (arr[i] > arr[i - 1] && in_valley) {
                started_incline = true;
            }

            if (arr[i] < arr[i - 1] && in_valley && started_incline) {
                ++valleys;
                break;
            }
        }

        if (valleys == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
