"""
! 출처: https://www.acmicpc.net/problem/27438
! 문제: 영화감독 숌 2
! 난이도: 골드 4
! 알고리즘 분류: 브루트포스, 런터임 전의 전처리
"""

# * 전처리 코드

N = 140000
_arr = []

count = 0
i = 666
n = 1
while n < N:
    while True:
        curr = str(i)
        
        if "666" in curr:
            count += 1
            if count == n:
                break
        
        i += 1
    n += 10000
    _arr.append(i)

print(_arr)
    

# * 풀이 1

