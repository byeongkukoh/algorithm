"""
! 출처: https://www.acmicpc.net/problem/2744
! 문제: 대소문자 바꾸기
! 난이도: 브론즈 5
! 알고리즘 분류: 구현, 문자열
"""

# * 풀이 1

strs = list(input())
res = []

for i in strs:
    if i.isupper():
        res.append(i.lower())
    else:
        res.append(i.upper())
        
for j in res:
    print(j, end='')
    
    
# * 풀이 2

# print(input().swapcase())