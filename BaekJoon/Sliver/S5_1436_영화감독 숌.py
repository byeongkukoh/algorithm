"""
! 출처: https://www.acmicpc.net/problem/1436
! 문제: 영화감독 숌
! 난이도: 실버 5
! 알고리즘 분류: 브루트포스
"""

# * 풀이 1

N = int(input())

count = 0
i = 666

while True:
    curr = str(i)
    if "666" in curr:
        count += 1
        if count == N:
            break
    
    i += 1
    
print(i)