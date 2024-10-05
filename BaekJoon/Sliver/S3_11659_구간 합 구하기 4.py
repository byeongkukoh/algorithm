"""
! 출처: https://www.acmicpc.net/problem/11659
! 문제: 구간 합 구하기 4
! 난이도: 실버 3
! 알고리즘 분류: 누적 합
"""

# * 풀이 1

import sys

N, M = map(int, sys.stdin.readline().split())

nums = list(map(int, sys.stdin.readline().split()))

sums = [0] * (N + 1)

for k in range(1, N+1):
    sums[k] = sums[k-1] + nums[k-1]

for m in range(M):
    i, j = map(int, sys.stdin.readline().split())

    print(sums[j] - sums[i-1])