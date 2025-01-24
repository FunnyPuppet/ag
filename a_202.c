#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getNext(int x) {
    int sum = 0;

    while (x > 0) {
        int d = x % 10;

        sum += d * d;

        x /= 10;
    }

    return sum;
}

bool isHappy(int n) {
    int fast = getNext(n), slow = n;

    while (fast != 1 && fast != slow) {
        fast = getNext(getNext(fast));
        slow = getNext(slow);
    }

    return fast == 1;
}

int main() {
    bool flag = isHappy(2);

    printf("%d\n", flag);

    return 0;
}

