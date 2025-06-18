"""
! 출처: https://www.acmicpc.net/problem/30501
! 문제: 관공... 어찌하여 목만 오셨소...
! 난이도: 브론즈 4
! 알고리즘 분류: 구현 | 문자열
"""

# * 풀이 1

N = int(input())

for _ in range(N):
    temp = input()
    
    if "S" in temp:
        res = temp
        
print(res)