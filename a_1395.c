#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int numTeams(int* rating, int ratingSize) {
    int ans = 0;

    for (int j = 1; j < ratingSize; j++) {
        int il = 0, im = 0;
        int kl = 0, km = 0;

        for (int i = 0; i < j; i++) {
            if (rating[i] < rating[j]) {
                il++;
            }
            if (rating[i] > rating[j]) {
                im++;
            }
        }

        for (int k = j + 1; k < ratingSize; k++) {
            if (rating[j] < rating[k]) {
                km++;
            }
            if (rating[j] > rating[k]) {
                kl++;
            }
        }
        ans += il * km + im * kl;
    }

    return ans;
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = numTeams(nums, len);
    printf("%d\n", res);

    return 0;
}