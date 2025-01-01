#include <stdio.h>
#include <stdlib.h>

// 归并排序

void merge(int* nums, int* temp, int left, int mid, int right) {
    int l_pos = left;
    int r_pos = mid + 1;
    int pos = left;

    while (l_pos <= mid && r_pos <= right) {
        if (nums[l_pos] > nums[r_pos]) {
            temp[pos++] = nums[l_pos++];
        } else {
            temp[pos++] = nums[r_pos++];
        }
    }

    while (l_pos <= mid) {
        temp[pos++] = nums[l_pos++];
    }

    while (r_pos <= right) {
        temp[pos++] = nums[r_pos++];
    }

    while (left <= right) {
        nums[left] = temp[left];
        left++;
    }
}

void sort(int* nums, int* temp, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    sort(nums, temp, left, mid);
    sort(nums, temp, mid + 1, right);

    merge(nums, temp, left, mid, right);
}


int main(void) {
    int nums[] = {4, 2, 7, 3, 1, 9, 8, 6, 11};

    int len = sizeof(nums) / sizeof(nums[0]);

    int temp[len];

    sort(nums, temp, 0, len - 1);

    printf("Result: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", nums[i]);
    }

    return EXIT_SUCCESS;
}
