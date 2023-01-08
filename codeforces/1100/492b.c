#include <stdio.h>
#include <stdlib.h>
 
#define CAPACITY 1000
 
int cmp(const void * a, const void * b) {
    return (*(long long*)a > *(long long*)b);
}
 
int main(void) {
    int length;
    long long max_number;
    scanf("%d %lld", &length, &max_number);
 
    long long lanterns[CAPACITY];
    
    for (int i = 0; i < length; ++i) {
        scanf("%lldd", &lanterns[i]);
    }
 
    qsort(lanterns, length, sizeof(long long), cmp);
 
    long long largest_gap = 0;
 
    if (lanterns[0] != 0) {
        largest_gap = lanterns[0] * 2;
    } else if (max_number > 1) {
        largest_gap = lanterns[1] - lanterns[2];
    }
 
    for (int i = 1; i < length - 1; ++i) {
        if (lanterns[i + 1] - lanterns[i] > largest_gap) {
            largest_gap = lanterns[i + 1] - lanterns[i];
        }
    }
 
    if (lanterns[length - 1] != max_number) {
        if ((length - lanterns[length - 1]) * 2 > largest_gap) {
            largest_gap = (length - lanterns[length - 1]) * 2;
        }
    }
 
    printf("%lf\n", ((double)largest_gap) / 2.0);
 
    return 0;
}
