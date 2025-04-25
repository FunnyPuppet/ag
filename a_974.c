#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int subarraysDivByK(int* nums, int numsSize, int k) {
    int cnt[k];
    memset(cnt, 0, sizeof(cnt));
    cnt[0] = 1;
    int ans = 0, sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        ans += cnt[(sum % k + k) % k]++;
    }
    return ans;
}

int main() {
    int cardPoints[] = {1,2,3,4,5,6,1};
    int len = sizeof(cardPoints) / sizeof(cardPoints[0]);
    int res = subarraysDivByK(cardPoints, len, 3);
    printf("%d\n", res);

    return 0;
}