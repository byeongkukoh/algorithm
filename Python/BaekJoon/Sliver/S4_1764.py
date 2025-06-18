"""
! 출처: https://www.acmicpc.net/problem/1764
! 문제: 듣보잡
! 난이도: 실버 4
! 알고리즘 분류: 자료 구조 | 문자열 | 정렬 | 해시를 사용한 집합과 맵
"""

# * 풀이 1
# ! 문제를 잘 읽자!!

N, M = map(int, input().split())

hash_table = {}
for _ in range(N+M):
    name = input()

    if name in hash_table.keys():
        hash_table[name] += 1
    else:
        hash_table[name] = 1

res = []

for key, value in hash_table.items():
    if value == 2:
        res.append(key)

res.sort()

print(len(res))
for i in res:
    print(i)