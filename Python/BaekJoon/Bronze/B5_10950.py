"""
! 출처: https://www.acmicpc.net/problem/10950
! 문제: A+B - 3
! 난이도: 브론즈 5
! 알고리즘 분류: 수학 | 구현 | 사칙연산
"""

T = int(input())

for _ in range(T):
    A, B = map(int, input().split())
    print(A+B)