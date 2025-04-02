#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

typedef long long ll;

ll max(ll a, ll b) {
    return a > b ? a : b;
}

ll maximumTripletValue(int* nums, int numsSize) {
    ll ans = 0, imax = 0, dmax = 0;

    for (int k = 0; k < numsSize; k++) {
        ans = max(ans, dmax * nums[k]);
        dmax = max(dmax, imax - nums[k]);
        imax = max(imax, (ll)nums[k]);
    }

    return ans;
}

int main() {
    int prices[] = {1000000,1,1000000};
    int len = sizeof(prices) / sizeof(prices[0]);

    long long res = maximumTripletValue(prices, len);
    printf("%lld\n", res);

    return 0;
}