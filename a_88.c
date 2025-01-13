#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int l = 0, r = 0;
    int *res = malloc(sizeof(int) * nums1Size);

    while (l < m && r < n) {
        if (nums1[l] < nums2[r]) {
            res[l + r] = nums1[l];
            l++;
        } else {
            res[l + r] = nums2[r];
            r++;
        }
    }

    while (l < m) {
        res[l + r] = nums1[l];
        l++;
    }

    while (r < n) {
        res[l + r] = nums2[r];
        r++;
    }

    for (int i = 0; i < nums1Size; i++) {
        nums1[i] = res[i];
    }

    free(res);
}

int main() {
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums2[] = {2, 5, 6};

    int m = 3, n = 3;

    merge(nums1, sizeof(nums1) / sizeof(nums1[0]), m, nums2, sizeof(nums2) / sizeof(nums2[0]), n);

    return 0;
}

