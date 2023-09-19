#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100], s2[100];

    scanf("%[^\n]s", s1); // input till new line entered

    printf("%d\n", strlen(s1)); // does not include last null value

    // char *strcpy(char *destination, const char *source);
    strcpy(s2, s1);
    printf("%s\n", s2);

    // strcmp: 0(a, a), -1(b, 1), 1(a, b)
    printf("%d\n", strcmp(s1, s2));

    // unsigned char : 0 to 255
    // signed char : -128 to 127
    unsigned char ch1 = 97;
    printf("%c\n", ch1);
    unsigned char ch2 = -97;
    printf("%c\n", ch2);
    signed char ch3 = 97;
    printf("%c\n", ch3);
    signed char ch4 = -97;
    printf("%c\n", ch4);
    return 0;
}