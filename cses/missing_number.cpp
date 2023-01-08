#include <cstdio>
#include <vector>
using namespace std;

// This problem has an easy solution using the Natural Numbers Formula
// NNF gives the sum of numbers in a range: 1 + 2 + 3 + 4 ... n
// NNF is (n * (n + 1)) / 2
// Then we subtract the sum of these numbers from that formula's result
// to find the missing number.
//
// n is always at least two
// n is at most 200000
// max is ~20 billion, so need 64 bit ints

int main(void) {
    long long n;
    scanf("%lld", &n);
    long long sum = 0;

    for (int i = 0; i < n - 1; ++i) {
        long long x;
        scanf("%lld", &x);
        sum += x;
    }

    long long nnf = (n * (n + 1)) / 2;
    printf("%lld\n", nnf - sum);

    return 0;
}
