#include <cstdio>
#include <cstdlib>

int cmp(const void* a, const void* b) {
    return (*(int*)a) > (*(int*)b);
}

int main(void) {
    int n;
    scanf("%d", &n);

    while (n--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int nums[3] = {a, b, c};
        qsort(nums, 3, sizeof(int), cmp);
        printf("%d\n", nums[1]);
    }
}
