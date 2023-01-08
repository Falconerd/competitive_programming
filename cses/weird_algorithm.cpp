#include <cstdio>
using namespace std;

//  WEIRD(N)
//      while N < 1
//          if N is even
//              N = N / 2
//          else
//              N = N * 3 + 1
//          print N
//      end while
//  print 1

int main(void) {
    long long n;
    scanf("%lld", &n);

    while (n > 1) {
        printf("%lld ", n);

        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }
    }

    printf("1\n");
    return 0;
}
