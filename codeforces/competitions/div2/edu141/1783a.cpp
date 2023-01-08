#include <cstdio>
using namespace std;

// Not finished, too hard for my smooth brain

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int length;
        int arr[50];
        scanf("%d", &length);
        for (int l = 0; l < length; ++l) {
            scanf("%d", &arr[l]);
        }

        // Check if array is beautiful.
        int sum = 0;
        int beautiful = 1;
        for (int j = 0; j < length; ++j) {
            if (arr[j] == sum && j != length - 1) {
                arr[j + 1] = arr[j] ^ arr[j + 1];
                arr[j] = arr[j] ^ arr[j + 1];
                arr[j + 1] = arr[j] ^ arr[j + 1];
            }

            if (arr[j] == sum) {
                beautiful = 0;
                break;
            }
            sum += arr[j];
        }

        if (beautiful) {
            printf("YES\n");
            for (int j = 0; j < length - 1; ++j) {
                printf("%d ", arr[j]);
            }
            printf("%d\n", arr[length - 1]);
        } else {
            printf("NO\n");
        }
    }
}
