#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int divisorSubstrings(int num, int k) {
    int ans = 0;
    int i = num;
    while(i >= pow(10,k-1)){
        int t = i % (int)pow(10,k);
        if(t != 0 && num % t == 0) {
            ans++;
        }
        i /= 10;
    }
    return ans;
}

int main() {
    int res = divisorSubstrings(430043, 2);
    printf("%d\n", res);

    return 0;
}