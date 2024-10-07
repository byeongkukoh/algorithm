"""
! 출처: https://www.acmicpc.net/problem/10430
! 문제: 나머지
! 난이도: 브론즈 5
! 알고리즘 분류: 수학, 구현, 사칙연산
"""

# * 풀이 1

A, B, C = map(int, input().split())

print((A + B) % C)
print(((A % C) + (B % C)) % C)
print((A * B) % C)
print(((A % C) * (B % C)) % C)