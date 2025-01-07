T = int(input())

for t in range(T):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    res = []

    if n < m:
        for i in range(m-n+1):
            sum = 0
            for j in range(n):
                sum += (a[j] * b[j + i])
            res.append(sum)
    else:
        for i in range(n-m+1):
            sum = 0
            for j in range(m):
                sum += (a[j + i] * b[j])
            res.append(sum)

    print(f"#{t+1} {max(res)}")