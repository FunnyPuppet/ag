#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int longestCycle(int* edges, int edgesSize) {
    int n = edgesSize;
    int label[n];
    memset(label, 0, sizeof(label));

    int cur = 0, ans = -1;
    for (int i = 0; i < n; ++i) {
        if (label[i]) {
            continue;
        }
        int pos = i, start = cur;
        while (pos != -1) {
            ++cur;
            if (label[pos]) {
                if (label[pos] > start) {
                    ans = fmax(ans, cur - label[pos]);
                }
                break;
            }
            label[pos] = cur;
            pos = edges[pos];
        }
    }

    return ans;
}

int main() {
    int edges[] = {3, 3, 4, 2, 3};
    int len = sizeof(edges) / sizeof(edges[0]);
    int res = longestCycle(edges, len);
    printf("%d", res);

    return 0;
}