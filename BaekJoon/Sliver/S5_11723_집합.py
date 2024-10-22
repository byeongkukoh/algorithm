"""
! 출처: https://www.acmicpc.net/problem/11723
! 문제: 집합
! 난이도: 실버 5
! 알고리즘 분류: 구현 / 비트마스킹
"""

# * 풀이 3

import sys

M = int(sys.stdin.readline().strip())

res = set()

for _ in range(M):
    text = sys.stdin.readline().strip()

    if text == "all":
        res = set([i for i in range(1, 21)])
    elif text == "empty":
        res = set()
    else:
        operator, num = text.split()

        if operator == "add":
            res.add(int(num))
        elif operator == "remove":
            res.discard(int(num))
        elif operator == "check":
            if int(num) in res:
                print(1)
            else:
                print(0)
        elif operator == "toggle":
            if int(num) in res:
                res.discard(int(num))
            else:
                res.add(int(num))

# ============================================================#

# * 풀이 2
# ! 시간 초과
# ! match-case 시간복잡도가 어떻게 되지..? if-else보다 느린가?

# M = int(input())

# res = set()

# for _ in range(M):
#     text = input()
#     if text == "all" or text == "empty":
#         operator = text
#     else:
#         operator, num = text.split()

#     match operator:
#         case "add":
#             if int(num) not in res:
#                 res.add(int(num))
#         case "remove":
#             if int(num) in res:
#                 res.remove(int(num))
#         case "check":
#             if int(num) in res:
#                 print(1)
#             else:
#                 print(0)
#         case "toggle":
#             if int(num) in res:
#                 res.remove(int(num))
#             else:
#                 res.add(int(num))
#         case "all":
#             res = set([i for i in range(1, 21)])
#         case empty:
#             res = set()

# ============================================================#

# * 풀이 1
# ! 시간 초과
# ! list와 set 시간복잡도

# M = int(input())

# res = []

# for _ in range(M):
#     text = input()
#     if text == "all" or text == "empty":
#         operator = text
#     else:
#         operator, num = text.split()

#     match operator:
#         case "add":
#             if int(num) not in res:
#                 res.append(int(num))
#         case "remove":
#             if int(num) in res:
#                 res.remove(int(num))
#         case "check":
#             if int(num) in res:
#                 print(1)
#             else:
#                 print(0)
#         case "toggle":
#             if int(num) in res:
#                 res.remove(int(num))
#             else:
#                 res.append(int(num))
#         case "all":
#             res = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
#         case empty:
#             res = []