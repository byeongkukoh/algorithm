"""
! 출처: https://www.acmicpc.net/problem/10250
! 문제: ACM 호텔
! 난이도: 브론즈 3
! 알고리즘 분류: 수학, 구현, 사칙연산
"""

# * 풀이 1

T = int(input())

for test in range(T):
    H, W, N = map(int, input().split())

    w = 1
    while H * w < N:
        w += 1

    h = 1
    while H * (w - 1) + h < N:
        h += 1

    print(str(h) + str(w).zfill(2))