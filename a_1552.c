#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <tgmath.h>

int compareInt(const void* a, const void* b) {
    int int_a = *(int*)a;
    int int_b = *(int*)b;

    return int_a - int_b;
}

bool canPlace(int* position, int positionSize, int m, int maxDist) {
    int count = 1;
    int lastPosition = position[0];

    for (int i = 0; i < positionSize; i++) {
        if (position[i] - lastPosition >= maxDist) {
            count++;
            lastPosition = position[i];
            if (count == m) {
                return true;
            }
        }
    }

    return false;
}

int maxDistance(int* position, int positionSize, int m) {
    qsort(position, positionSize, sizeof(int), compareInt);

    int left = 1;
    int right = (position[positionSize - 1] - position[0]) / (m - 1);
    int result = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlace(position, positionSize, m, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    int nums[] = {1, 2, 3, 4, 7};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = maxDistance(nums, len, 3);
    printf("%d\n", res);

    return 0;
}