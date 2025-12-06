def cal(a, b, x):
    return a * (x - 1) + b

n = int(input())

for _ in range(n):
    a, b, x = map(int, input().split())

    print(cal(a, b, x))