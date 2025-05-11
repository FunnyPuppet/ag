#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

typedef long long ll;

long long* findPrefixScore(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;
    ll x = 0;
    ll *ans = malloc(sizeof(ll) * n);
    *returnSize = n;
    int m = 0;

    for (int i = 0; i < n; ++i) {
        m = fmax(m, nums[i]);
        x += (ll)nums[i] + m;
        ans[i] = x;
    }

    return ans;
}

int main() {

    return 0;
}