"""
! 출처: https://www.acmicpc.net/problem/9086
! 문제: 문자열
! 난이도: 브론즈 5
! 알고리즘 분류: 구현 | 문자열
"""

T = int(input())

for _ in range(T):
    _str = input()

    print(_str[0] + _str[-1])