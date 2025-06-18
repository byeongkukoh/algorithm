"""
! 출처: https://www.acmicpc.net/problem/8393
! 문제: 합
! 난이도: 브론즈 5
! 알고리즘 분류: 수학, 구현
"""

# * 풀이 1

n = int(input())
res = 0

for i in range(n):
    res += (i+1)
    
print(res)