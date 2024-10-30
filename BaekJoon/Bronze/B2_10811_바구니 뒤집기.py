"""
! 출처: https://www.acmicpc.net/problem/10811
! 문제: 바구니 뒤집기
! 난이도: 브론즈 2
! 알고리즘 분류: 구현 | 시뮬레이션
"""

# * 풀이 1

N, M = map(int, input().split())

nums = [i for i in range(1, N+1)]

for m in range(M):
    i, j = map(int, input().split())
    
    temp_1 = nums[:i-1]
    temp_2 = nums[i-1:j]
    
    temp_2.reverse()
    
    if j != N:
        temp_3 = nums[j:]
        nums = temp_1 + temp_2 + temp_3
    else:
        nums = temp_1 + temp_2
    
print(*nums)