#include <cstdio>
#include <stdio.h>
using namespace std;

// Analyzing other people's solutions - since I was stuck on this for an hour.
// Sorry, forgot who wrote this solution originally.
// I'm still not sure how it works, need to simulate it.
// NOTE: Should also check out the editorial when it comes out.
int main(void) {
    int test_cases;
    scanf("%d", &test_cases);

    while (test_cases--) {
        int length;
        scanf("%d", &length);
        int arr[length + 10]; // Why + 10?

        // Why start at 1?
        // I think they are just used to python.
        for (int j = 1; j <= length; ++j) {
            scanf("%d", &arr[j]);
        }

        // Since 0th is unused, first and last are 1-indexed
        if (arr[1] == arr[length]) {
            // No because the arry is sorted so a sequence of the same number must add up at the second one.
            // There are always at least 2 entries, so [10, 10] for example.
            printf("NO\n");
        } else {
            printf("YES\n");

            int k = length;

            // Iterate backwards until finding no duplicate.
            // Because duplicates won't add up to one another after 0.
            // [3, 10, 10, 10, 10]
            //  3  13  23  33  43
            while (arr[k] == arr[length]) {
                --k;
            }

            // Print all values before the duplicates.
            // Print from right left until the duplicates.
            // Because the array is sorted, and descending numbers
            // cannot add up to one another in a running total.
            for (int j = k + 1; j >= 1; --j) {
                printf("%d ", arr[j]);
            }

            // Iterate backwards over the duplicates.
            for (int j = length; j > k + 1; --j) {
                printf("%d ", arr[j]);
            }
            
            printf("\n");
        }
    }

    return 0;
}

// Not finished, too hard for my smooth brain

//int main(void) {
//    int n;
//    scanf("%d", &n);
//
//    for (int i = 0; i < n; ++i) {
//        int length;
//        int arr[50];
//        scanf("%d", &length);
//        for (int l = 0; l < length; ++l) {
//            scanf("%d", &arr[l]);
//        }
//
//        // Check if array is beautiful.
//        int sum = 0;
//        int beautiful = 1;
//        for (int j = 0; j < length; ++j) {
//            if (arr[j] == sum && j != length - 1) {
//                arr[j + 1] = arr[j] ^ arr[j + 1];
//                arr[j] = arr[j] ^ arr[j + 1];
//                arr[j + 1] = arr[j] ^ arr[j + 1];
//            }
//
//            if (arr[j] == sum) {
//                beautiful = 0;
//                break;
//            }
//            sum += arr[j];
//        }
//
//        if (beautiful) {
//            printf("YES\n");
//            for (int j = 0; j < length - 1; ++j) {
//                printf("%d ", arr[j]);
//            }
//            printf("%d\n", arr[length - 1]);
//        } else {
//            printf("NO\n");
//        }
//    }
//}
