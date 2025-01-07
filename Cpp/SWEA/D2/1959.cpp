#include <stdio.h>

int main()
{
    // 테스트 케이스 입력
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
    {
        // N과 M 값 입력
        int n, m;
        scanf("%d %d", &n, &m);

        int a[n], b[m];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &b[i]);
        }

        int max_length = n < m ? m - n + 1 : n - m + 1;
        int res[max_length];

        // 주어진 조건에 따라 계산
        if (n < m)
        {
            for (int i = 0; i < m - n + 1; i++)
            {
                int sum = 0;
                for (int j = 0; j < n; j++)
                {
                    sum += (a[j] * b[j + i]);
                }
                res[i] = sum;
            }
            // 최대값 찾기
            int max = res[0];

            for (int k = 1; k < m - n + 1; k++)
            {
                if (max < res[k])
                {
                    max = res[k];
                }
            }

            printf("#%d %d\n", t + 1, max);
        }
        else
        {
            for (int i = 0; i < n - m + 1; i++)
            {
                int sum = 0;
                for (int j = 0; j < m; j++)
                {
                    sum += (a[j + i] * b[j]);
                }
                res[i] = sum;
            }
            // 최대값 찾기
            int max = res[0];

            for (int k = 1; k < n - m + 1; k++)
            {
                if (max < res[k])
                {
                    max = res[k];
                }
            }

            printf("#%d %d\n", t + 1, max);
        }
    }

    return 0;
}