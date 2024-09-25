"""
! 출처: https://www.acmicpc.net/problem/1912
! 문제: 연속합
! 난이도: 실버 2
! 알고리즘 분류: 다이나믹 프로그래밍(DP)
"""

# * 풀이 1

def func(f, n):
    if f + n > n:
        return f + n
    else:
        return n
    
N = int(input())
n_arr = list(map(int, input().split()))

f = n_arr[0]
temp = f

for i in range(1, N):
    f = func(f, n_arr[i])
    
    if f > temp:
        temp = f
    
print(temp)