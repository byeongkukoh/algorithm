#include <stdio.h>

int main()
{
    int test;
    scanf("%d", &test);

    int n = 1;

    for (int t = 0; t <= test; t++)
    {
        printf("%d ", n);
        n = n * 2;
    }

    return 0;
}