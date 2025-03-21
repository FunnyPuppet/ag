#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int longestValidParentheses(char* s) {
    int n = strlen(s);

    if (n == 0) {
        return 0;
    }

    int stack[n + 1];
    int top = -1;
    stack[++top] = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            --top;
            if (top == -1) {
                stack[++top] = i;
            } else {
                ans = fmax(ans, i - stack[top]);
            }
        }
    }

    return ans;
}

int main() {
    int res = longestValidParentheses("()(())");
    printf("%d\n", res);

    return 0;
}