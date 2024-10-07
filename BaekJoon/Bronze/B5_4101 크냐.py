"""
! 출처: https://www.acmicpc.net/problem/4101
! 문제: 크냐?
! 난이도: 브론즈 5
! 알고리즘 분류: 구현
"""

# * 풀이 1

while True:
    a, b = map(int, input().split())
    
    if a == 0 & b == 0:
        break
    
    if a > b:
        print("Yes")
    else:
        print("No")