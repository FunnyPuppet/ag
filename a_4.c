#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total_size = nums1Size + nums2Size;
    int o_pos = 0, t_pos = 0, prev = 0, cur = 0;
    int mid = total_size / 2;

    for (int i = 0; i <= mid; i++) {
        prev = cur;

	if (o_pos < nums1Size && (t_pos >= nums2Size || nums1[o_pos] <= nums2[t_pos])) {
	    cur = nums1[o_pos++];
	} else {
	    cur = nums2[t_pos++];
	}
    }

    if (total_size % 2 == 1) {
        return cur;
    } else {
        return (cur + prev) * 0.5;
    }
}

int main(int argc, char *argv[]) {
    int nums1[] = {2, 5, 7, 9};
    int nums2[] = {1};

    double res = findMedianSortedArrays(nums1, 4, nums2, 1);

    printf("Result is: %f\n", res);

    return EXIT_SUCCESS;
}
