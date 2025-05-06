#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int* partitionLabels(char* s, int* returnSize) {
    int hash[26] = {0}, t[26] = {0};
    int *ans = malloc(sizeof(int) * 26);
    *returnSize = 0;
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        hash[s[i] - 'a']++;
    }

    int cnt = 0, l = 0;

    for (int i = 0; i < n ;i++) {
        int idx = s[i] - 'a';
        if (t[idx] == 0) {
            t[idx]++;
            cnt++;
        }
        if (--hash[idx] == 0) {
            cnt--;
            if (cnt == 0) {
                ans[*returnSize] = i - l + 1;
                (*returnSize)++;
                l = i + 1;
            }
        }
    }

    return ans;
}

int main() {
    int returnSize;
    int *res = partitionLabels("ababcbacadefegdehijhklij", &returnSize);
    free(res);

    return 0;
}