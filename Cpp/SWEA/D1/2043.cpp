#include <stdio.h>

int main()
{
    int p, k;
    scanf("%d %d", &p, &k);

    int cnt = 1;

    for (int i = k; i <= p; i++)
    {
        if (i == p)
        {
            break;
        }
        cnt++;
    }

    printf("%d", cnt);
}