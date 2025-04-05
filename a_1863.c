#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

void dfs(int* ans, int val, int idx, int* nums, int numsSize){
    if(idx == numsSize){
        *ans += val;
        return;
    }
    dfs(ans, val ^ nums[idx], idx + 1, nums, numsSize);
    dfs(ans, val, idx + 1, nums, numsSize);

}

int subsetXORSum(int* nums, int numsSize) {
    int ans = 0;
    dfs(&ans, 0, 0, nums, numsSize);
    return ans;
}

int main() {
    int nums[] = {1, 2, 3};
    int len = sizeof(nums) / sizeof(nums[0]);

    int res = subsetXORSum(nums, len);
    printf("%d\n", res);

    return 0;
}