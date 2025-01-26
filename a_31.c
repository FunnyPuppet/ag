#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void nextPermutation(int* nums, int numsSize) {
    int l = 0;
    for (int i = numsSize - 1; i > 0; i--) {
        if (nums[i] > nums[i - 1]) {
            int min = i;
            while (min < numsSize - 1) {
                if (nums[min + 1] <= nums[i - 1]) {
                    break;
                }
                min++;
            }
            swap(&nums[min], &nums[i - 1]);

            l = i;
            break;
        }
    }

    quickSort(nums, l, numsSize - 1);
}

int main() {
    int nums[] = {1,1,5};
    int len = sizeof(nums) / sizeof(nums[0]);

    nextPermutation(nums, len);

    for (int i = 0; i < len; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}
