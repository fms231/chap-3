#include <stdio.h>

void reverse(char s[], int n){
    int i, j;
    char c;
    for (i = 0, j = n - 1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itob(int n, char s[], int b){
    int i, sign;
    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if ((sign = n) < 0){
        n = -n;
    }
    i = 0;
    do {
        s[i++] = digits[n % b];
    } while ((n /= b) > 0);
    if (sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s, i);
}

int main(void)
{
    char s[100];
    int n = 8;
    int b = 8;
    itob(n, s, b);
    printf("Integer %d to base %d: %s\n", n, b, s);
    return 0;
}