#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool isValid(char* s) {
    int len = strlen(s);

    if (len == 1) {
        return false;
    }

    char stack[len + 1];
    int top = -1;

    for (int i = 0; i < len; i++) {
        char ch = s[i];
        if (top >= 0 && (ch == ')' || ch == ']' || ch == '}')) {
            if ((ch == ')' && stack[top] != '(') || (ch == ']' && stack[top] != '[') || (ch == '}' && stack[top] != '{')) {
                return false;
            }
            top--;
        } else {
            stack[++top] = s[i];
        }
    }

    return top == -1;
}

int main() {
    bool v = isValid("({})");
    printf("%d", v);

    return 0;
}

