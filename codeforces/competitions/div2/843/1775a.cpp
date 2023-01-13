#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

// it seems in C++ we can directly compare these strings.
// bb > b, aaa > aa
// but aaa < ab
// names can be up to 500 chars, so...
// this seems like a DP problem
// 
// RULES: a <= b AND c <= b
//     OR a >= b AND c >= b
//     OR BOTH
//
// in this case, the only way to split is b bb a
// bbba
// bb b a
// a >= b AND c >= b
// BUT b is a prefix of c and b != c, so b < c
// b < bb 
// a < bb
//
//
// N = 4
// S = [b b b a]
// R = N - 1
// L = N - 1
// while a
//
//
//
//    thought i was onto something when i was taking a dump but i was wrong
//
//    input has examples of ab being next to each other... though never a ba?
// 
// abbba would probably be 
// ab b ba
// let's test...
// seems that wouldn't work
// "b" > "ab", but "b" < "ba"
//
// a bbb a should work
// ab bb a should also work...
//
// let's just try the naive two pointer scanning idea...
//
// N = 5
// S = "abbba"
// R = N / 2
// L = N / 2
// while L >= 0 && R < N do
//     a = SUBSTRING(0, L)
//     b = SUBSTRING(L, R)
//     c = SUBSTRING(R, N - 1)
//     if (c > b && a > b) || (c < b && a < b) then
//         break;
//     end
//     --L;
//     ++R;
// end
//
//
//

void solve() {
    string s;
    cin >> s;

    int n = s.length();
    int r = n / 2;
    int l = n / 2;

    //string x = "12345";
    //string a = x.substr(0, max(l, 1));
    //string b = x.substr(l, max(r - l, 1));
    //string c = x.substr(r + 1);

    //cout << "l: " << l << endl;
    //cout << "r: " << r << endl;
    //cout << "a: " << a << endl;
    //cout << "c: " << c << endl;
    //cout << "b: " << b << endl;

    //exit(0);

    cout << "--" << endl;
    cout << s << endl;
    cout << "n: " << n << endl;

    while (l >= 0 && r < n) {
        string a = s.substr(0, max(l, 1));
        string b = s.substr(l, max(r - l, 1));
        string c = s.substr(r);

        int p = a.length();
        int x = b.length();
        int q = c.length();

        if (p + q + x > n) {
            cout << "SOMETHING IS WRONG" << endl;
        }

        cout << "p, q: " << p << ", " << q << endl;

        //cout << "a: " << a << endl;
        //cout << "b: " << b << endl;
        //cout << "c: " << c << endl;
        //cout << "r: " << r << endl;

        //cout << "r: " << r << "'" << s.substr(r) << "'" << endl;
        //cout << " " << l << " " << r << " " << r - l << endl;

        if ((c >= b && a >= b) || (c <= b && a <= b)) {
            cout << a << " " << b << " " << c << endl;
            break;
        }

        --l;
        ++r;
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

