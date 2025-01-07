"""
! 출처: https://www.acmicpc.net/problem/10816
! 문제: 숫자 카드 2
! 난이도: 실버 4
! 알고리즘 분류: 자료 구조 | 정렬 | 이분 탐색 | 해시를 사용한 집합과 맵
"""

# * 풀이 1

N = int(input())

num_cards = input().split()

hash_table = {}

for card in num_cards:
    if card in hash_table:
        hash_table[card] += 1
    else:
        hash_table[card] = 1

M = int(input())

nums = input().split()

noc = []

for num in nums:
    if num in hash_table:
        noc.append(hash_table[num])
    else:
        noc.append(0)

print(*noc)