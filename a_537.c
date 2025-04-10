#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

char* complexNumberMultiply(char *num1, char *num2){
    int real1, imag1, real2, imag2;
    sscanf(num1, "%d+%di", &real1, &imag1);
    sscanf(num2, "%d+%di", &real2, &imag2);
    char *ans = (char *)malloc(sizeof(char) * 100);
    sprintf(ans, "%d+%di", real1 * real2 - imag1 * imag2, real1 * imag2 + real2 * imag1);
    return ans;
}

int main() {
    char *res = complexNumberMultiply("1+1i", "1+1i");
    printf("%s\n", res);

    return 0;
}