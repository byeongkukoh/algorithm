"""
! 출처: https://www.acmicpc.net/problem/2798
! 문제: 블랙잭
! 난이도: 브론즈 2
! 알고리즘 분류: 브루트포스
"""

# * 풀이 1

N, M = map(int, input().split())
cards = list(map(int, input().split()))

temp = 0

for i in range(N-2):
    for j in range(i+1, N-1):
        for k in range(j+1, N):
            sum_n = cards[i] + cards[j] + cards[k]
            
            if (sum_n <= M) and (M - sum_n < M - temp):
                temp = sum_n

print(temp)