"""
! 출처: https://www.acmicpc.net/problem/15964
! 문제: 이상한 기호
! 난이도: 브론즈 5
! 알고리즘 분류: 수학, 구현, 사칙연산
"""

# * 풀이 1

def new_cal_symbol(a, b):
    return (a+b) * (a-b)

a, b = map(int, input().split())

print(new_cal_symbol(a, b))