#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize) {
    int hash[101] = {0};

    for (int i = 0; i < nums1Size; i++) {
        if (hash[nums1[i]] == 0) {
            hash[nums1[i]] = 1;
        }
    }

    *returnSize = 0;
    for (int i = 0; i < nums2Size; i++) {
        if (hash[nums2[i]] == 1) {
            hash[nums2[i]] = 2;
            (*returnSize)++;
        }
    }

    for (int i = 0; i < nums2Size; i++) {
        if (hash[nums2[i]] == 0) {
            hash[nums2[i]] = 1;
        }
    }

    for (int i = 0; i < nums3Size; i++) {
        if (hash[nums3[i]] == 1) {
            hash[nums3[i]] = 2;
            (*returnSize)++;
        }
    }

    int *res = malloc(sizeof(int) * *returnSize);
    int pos = 0;
    for (int i = 0; i < 101; i++) {
        if (hash[i] > 1) {
            res[pos++] = i;
        }
    }

    return res;
}

int main() {

    return 0;
}

