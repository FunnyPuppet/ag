#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASH_SIZE 1001

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int set[HASH_SIZE] = {0};
    int ist[HASH_SIZE] = {0};

    for(int i = 0; i < nums1Size; i++) {
        set[nums1[i]] = 1;
    }

    int count = 0;
    for(int i = 0; i < nums2Size; i++) {
	int num = nums2[i];
        if (set[num]) {
	    set[num] = 0;
	    ist[count++] = num;
	}
    }

    int *res = malloc(sizeof(int) * count);

    for(int i = 0; i < count; i++) {
	res[i] = ist[i];
    }

    *returnSize = count;
    return res;
}

int main(int argc, char *argv[]) {
    int returnSize;
    int nums1[] = {2, 5, 7, 11};
    int nums2[] = {2, 5};
    int *res = intersect(nums1, 4, nums2, 2, &returnSize);

    printf("Size: %d; Result: %d %d\n", returnSize, res[0], res[1]);
    return EXIT_SUCCESS;
}
