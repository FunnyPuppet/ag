#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int minCostClimbingStairs(int* cost, int costSize) {
    if (costSize == 2) {
        return cost[0] < cost[1] ? cost[0] : cost[1];
    }

    int arr[costSize];

    int min = INT_MAX;
    for (int i = 0; i < 2; i++) {
        arr[i] = cost[i];
        arr[i + 1] = cost[i + 1];

        for (int j = i + 2; j < costSize; j++) {
            int o = arr[j - 2] + cost[j];
            int t = arr[j - 1] + cost[j];
            if (j == costSize - 1) {
                t = arr[j - 1];
            }

            arr[j] = o < t ? o : t;
        }
        int n = arr[costSize - 1];
        if (i == 1) {
            n = n + arr[1];
        }

        min = min < n ? min : n;
    }

    return min;
}

int main() {
    int nums[] = {1,100,1,1,1,100,1,1,100,1};
    int len = sizeof(nums) / sizeof(nums[0]);

    int res = minCostClimbingStairs(nums, len);

    printf("%d ", res);

    return 0;
}
