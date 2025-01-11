#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int countKDifference(int* nums, int numsSize, int k) {
    int hash[101] = {0};

    for (int i = 0; i < numsSize; i++) {
        hash[*(nums + i)]++;
    }

    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (1 <= num - k && num - k <= 100) {
            count += hash[num - k];
        }
        if (1 <= num + k && num + k <= 100) {
            count += hash[num + k];
        }
        if (hash[num] > 0) {
            hash[num]--;
        }
    }

    return count;
}

int main() {
    int nums[50] = {33,90,62,43,21,96,20,18,84,74,61,100,5,11,4,67,96,18,6,68,82,32,76,33,93,33,71,32,30,63,37,46,95,51,63,77,63,84,52,78,66,76,66,9,73,92,79,65,29,42};
    int count = countKDifference(nums, 50, 64);

    printf("%d ", count);

    return 0;
}

