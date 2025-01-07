#include <stdio.h>

int main()
{
    int sum_num = 0;

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        sum_num += i;
    }

    printf("%d", sum_num);
}