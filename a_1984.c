#include <stdio.h>
#include <stdlib.h>

#define INSERTION_SORT_THRESHOLD 10

// 交换两个整数的值
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 插入排序，用于小规模数组排序
void insertionSort(int arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 选择三数取中作为基准
int medianOfThree(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    if (arr[low] > arr[mid]) swap(&arr[low], &arr[mid]);
    if (arr[low] > arr[high]) swap(&arr[low], &arr[high]);
    if (arr[mid] > arr[high]) swap(&arr[mid], &arr[high]);

    // 将中值放到最后一位，作为 pivot
    swap(&arr[mid], &arr[high]);
    return arr[high];
}

// 分区函数
int partition(int arr[], int low, int high) {
    int pivot = medianOfThree(arr, low, high);
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

// 快速排序主函数
void quickSort(int arr[], int low, int high) {
    while (low < high) {
        // 小数组切换为插入排序
        if (high - low + 1 <= INSERTION_SORT_THRESHOLD) {
            insertionSort(arr, low, high);
            return;
        }

        // 分区
        int pi = partition(arr, low, high);

        // 尾递归优化：递归较小的部分，迭代较大的部分
        if (pi - low < high - pi) {
            quickSort(arr, low, pi - 1);
            low = pi + 1;
        } else {
            quickSort(arr, pi + 1, high);
            high = pi - 1;
        }
    }
}

int minimumDifference(int* nums, int numsSize, int k) {
    quickSort(nums, 0, numsSize - 1);

    int min = 100000;
    for (int i = 0; i <= numsSize - k; i++) {
        int num = nums[i + k - 1] - nums[i];

        min = num > min ? min : num;
    }

    return min;
}

// 打印数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 主函数
int main() {
    int arr[] = {90};
    int n = sizeof(arr) / sizeof(arr[0]);

    minimumDifference(arr, n, 1);
    printf("array: ");
    printArray(arr, n);

    return 0;
}
