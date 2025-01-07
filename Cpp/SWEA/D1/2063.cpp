#include <stdio.h>
#include <algorithm>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    std::sort(arr, arr + n);

    printf("%d", arr[n / 2]);

    return 0;
}