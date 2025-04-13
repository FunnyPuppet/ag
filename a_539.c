#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int compareInt(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int timeToMinutes(const char* timeStr) {
    int hours, minutes;
    if (sscanf(timeStr, "%d:%d", &hours, &minutes) != 2) {
        return -1;
    }
    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59) {

        return -1;
    }
    return hours * 60 + minutes;
}

int findMinDifference(char** timePoints, int timePointsSize) {
    int n = timePointsSize;
    if (n > 1440) {
        return 0;
    }
    int nums[n];
    for (int i = 0; i < n; i++) {
        nums[i] = timeToMinutes(timePoints[i]);
    }
    qsort(nums, n, sizeof(int), compareInt);

    int ans = nums[0] + 1440 - nums[n - 1];
    for (int i = 1; i < n; i++) {
        ans = fmin(ans, nums[i] - nums[i - 1]);
    }

    return ans;
}

int main() {
    int num = timeToMinutes("00:00");
    printf("%d\n", num);
    return 0;
}