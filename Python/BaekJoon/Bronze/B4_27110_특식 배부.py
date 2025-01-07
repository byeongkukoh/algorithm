"""
! 출처: https://www.acmicpc.net/problem/27110
! 문제: 특식 배부
! 난이도: 브론즈 4
! 알고리즘 분류: 수학 / 사칙연산
"""

# * 풀이 1

N = int(input())

A, B, C = map(int, input().split())

res = 0

if A > N:
    res = res + N
else:
    res = res + A
    
if B > N:
    res = res + N
else:
    res = res + B
    
if C > N:
    res = res + N
else:
    res = res + C
    
print(res)