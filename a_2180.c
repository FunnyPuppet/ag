#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

bool valid(int num) {
    int ans = 0;
    while (num > 0) {
        ans += num % 10;
        num /= 10;
    }

    return ans % 2 == 0;
}

int countEven(int num) {
    int cnt = 0;
    for (int i = 1; i <= num; i++) {
        if (valid(i)) {
            cnt++;
        }
    }

    return cnt;
}

int main() {
    int res = countEven(45);
    printf("%d\n", res);

    return 0;
}