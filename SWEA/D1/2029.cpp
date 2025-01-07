#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        printf("#%d %d %d\n", t, a / b, a % b);
    }
    return 0;
}