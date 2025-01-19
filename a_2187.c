#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int compareInt(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

long long minimumTime(int* time, int timeSize, int totalTrips) {
    if (timeSize == 1) {
        return (long long)time[0] * totalTrips;
    }
    qsort(time, timeSize, sizeof(int), compareInt);

    long long l = 1, r = (long long)time[0] * totalTrips;

    while (l <= r) {
        long long m = l + (r - l) / 2;

        long long t = 0;
        for (size_t i = 0; i < timeSize; i++) {
            t += m / time[i];
        }

        if (totalTrips > t) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return l;
}

int main() {
    int nums[] = {5, 10, 10};
    int len = sizeof(nums) / sizeof(nums[0]);

    int res = minimumTime(nums, len, 9);

    printf("%d", res);

    return 0;
}
