#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main(void) {
    string s;
    cin >> s;

    int largest = 0;
    int i = s.length() - 1;

    while (i >= 0) {
        char c = s[i];
        int count = 0;

        while (c == s[i] && i >= 0) {
            ++count;
            --i;
        }

        if (count > largest) {
            largest = count;
        }
    }

    cout << largest << endl;

    return 0;
}
