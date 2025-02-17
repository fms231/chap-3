#include <stdio.h>

void escape(char s[], char t[]){
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++){
        switch (t[i]){
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

void unescape(char s[], char t[]){
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++) {
        switch (t[i]){
            case '\\':
                switch (t[++i]){
                    case 'n':
                        s[j++] = '\n';
                        break;
                    case 't':
                        s[j++] = '\t';
                        break;
                    default:
                        s[j++] = '\\';
                        s[j++] = t[i];
                        break;
                }
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

int main(void)
{
    char s[100];
    char t[] = "Hello, world!\n\tThis is a test.";
    escape(s, t);
    printf("Escaped string: %s\n", s);
    unescape(t, s);
    printf("Unescaped string: %s\n", t);
    return 0;
}
