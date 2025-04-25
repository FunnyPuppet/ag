#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int subarraySum(int* nums, int numsSize) {
    int n = numsSize, ans = 0;
    int prefix[n + 1];
    memset(prefix, 0, sizeof(prefix));

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
        ans += prefix[i + 1] - prefix[(int)fmax(0, i - nums[i])];
    }

    return ans;
}

int main() {
    int cardPoints[] = {1,2,3,4,5,6,1};
    int len = sizeof(cardPoints) / sizeof(cardPoints[0]);
    int res = subarraySum(cardPoints, len);
    printf("%d\n", res);

    return 0;
}