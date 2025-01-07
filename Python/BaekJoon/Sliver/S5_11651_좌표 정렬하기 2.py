"""
! 출처: https://www.acmicpc.net/problem/11651
! 문제: 좌표 정렬하기 2
! 난이도: 실버 5
! 알고리즘 분류: 정렬
"""

# * 풀이 1

N = int(input())
coors = []

for _ in range(N):
    coors.append(tuple(map(int, input().split())))
    
coors.sort(key=lambda x: (x[1], x[0]))

for x, y in coors:
    print(f"{x} {y}")