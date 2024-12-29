#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    if (a - b == 1)
        printf("A");
    else if (a - b == -2)
        printf("A");
    else if (a - b == -1)
        printf("B");
    else if (a - b == 2)
        printf("B");

    return 0;
}