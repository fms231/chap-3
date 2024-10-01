#include <stdio.h>
#define abs(x) ((x) < 0 ? -(x) : (x))

void reverse(char s[], int n){
    int i, j;
    char c;
    for (i = 0, j = n - 1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[]){
    int i, sign;

    sign = n;
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);

    if (sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s, i);
}

int main(void)
{
    char s[100];
    int n = -2147483648;
    itoa(n, s);
    printf("Integer to string: %s\n", s);
    return 0;
}