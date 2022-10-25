#include <ctype.h>
#include <stdio.h>
int main(void) {
    int ch;
    while ((ch = getchar()) != EOF) {
        putchar((unsigned char)ch);
    }
    return 0;
}