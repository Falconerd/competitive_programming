#include <bits/stdc++.h>
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
        string s;
        cin >> s;

        char max = 'a';
        while (n--) {
            if (s[n] > max) {
                max = s[n];
            }
        }
        
        cout << max - '`' << endl;
    }
}

