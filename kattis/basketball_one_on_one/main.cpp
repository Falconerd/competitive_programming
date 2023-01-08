#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    cout << s[s.length()-2] << endl;
}


// Below is my original code, very over-complicated and failing despite test cases I wrote all passing...
// The lesson is to always read the question carefully and consider that each "story device" is there for a reason.
// In this case - the person recording would stop when A or B wins the game... Why would there be any more values?

/*

Given a string of characters like:
A2B1A2B2A1A2A2A2
A is person A
B is person B
the number is points
First to 11 wins
Unless scoreA = scoreB = 10
then first to have two points more than the other wins
produce string "A" or "B" to indicate the winner

ALGO(S, N)
    scores = [a, b]
    rule = off

    for i..N-1, i += 2
        p = S[i] == "B"
        scores[p] += S[i + 1]

        if scores[p] == 11
            return S[i]

        if a == b == 10
            rule = on

        if rule == on && scores[p] > scores[!p]
            return 
    end for
    return a > b ? "A" : "B"

*/

//int main (void) {
//    string s;
//    cin >> s;
//
//    int scores[] = {0, 0};
//    int rule = 0;
//
//    for (int i = 0; i < s.length(); i += 2) {
//        int p = s[i] == 'B';
//        scores[p] += s[i + 1] - '0';
//
//        if (scores[p] == 11 && !rule) {
//            cout << s[i] << endl;
//            break;
//        }
//
//        if (scores[0] == 10 && scores[1] == 10) {
//            rule = 1;
//        }
//
//        if (rule && scores[p] > scores[!p] + 1) {
//            cout << s[i] << endl;
//        }
//    }
//
//    exit(0);
//}
