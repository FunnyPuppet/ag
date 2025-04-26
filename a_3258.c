#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int countKConstraintSubstrings(char* s, int k) {
    int n = strlen(s);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int zero = 0, one = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == '0') {
                zero++;
            }

            if (s[j] == '1') {
                one++;
            }

            if (zero > k && one > k) {
                break;
            }

            ans++;
        }
    }

    return ans;
}

int main() {
    int res = countKConstraintSubstrings("10101", 1);
    printf("%d\n", res);

    return 0;
}