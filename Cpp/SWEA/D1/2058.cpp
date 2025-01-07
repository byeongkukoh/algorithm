#include <stdio.h>
#include <string.h>

int main()
{
    char n[5];
    scanf("%s", &n);

    int sum = 0;

    for (int i = 0; i < strlen(n); i++)
    {
        sum += int(n[i] - '0');
    }

    printf("%d", sum);

    return 0;
}