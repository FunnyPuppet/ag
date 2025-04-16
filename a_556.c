#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

void swap(int* a, int* b) {
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

int intToArr(int num, int* arr) {
    int index = 0;
    if (num == 0) {
        arr[index++] = 0;
    } else {
        while (num > 0) {
            arr[index++] = num % 10;
            num /= 10;
        }
        // 反转数组以保证顺序正确
        for (int i = 0; i < index / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[index - i - 1];
            arr[index - i - 1] = temp;
        }
    }
    return index;
}

long long arrToInt(int* arr, int size) {
    long long num = 0;
    for (int i = 0; i < size; i++) {
        num = num * 10 + (long long)arr[i];
    }
    return num;
}

int nextGreaterElement(int n) {
    int arr[10];
    int idx = intToArr(n, arr);
    nextPermutation(arr, idx);
    long long ans = arrToInt(arr, idx);
    if (ans <= n || ans > INT_MAX) {
        return -1;
    }
    return ans;
}

int main() {
    int res = nextGreaterElement(21);
    printf("%d\n", res);

    return 0;
}