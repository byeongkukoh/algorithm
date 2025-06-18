"""
! 출처: https://www.acmicpc.net/problem/10870
! 문제: 피보나치 수 5
! 난이도: 브론즈 2
! 알고리즘 분류: 수학 | 구현
"""

# * 풀이 1

def fibo(a, b):
    return a + b

a = 0
b = 1

n = int(input())

if n == 0:
    print(0)
    
elif n == 1:
    print(1)
    
else:
    for _ in range(n-1):
        temp = fibo(a, b)
        a = b
        b = temp

    print(b)