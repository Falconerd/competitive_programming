#include <stdio.h>

int main(void) {
    double withdrawal_amount, balance;
    scanf("%lf %lf", &withdrawal_amount, &balance);

    if (balance > withdrawal_amount && (int)withdrawal_amount % 5 == 0) {
        balance -= withdrawal_amount;
        balance -= 0.5;
    }

    printf("%lf\n", balance);

    return 0;
}
