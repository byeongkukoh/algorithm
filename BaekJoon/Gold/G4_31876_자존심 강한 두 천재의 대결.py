"""
! 출처: https://www.acmicpc.net/problem/31876
! 문제: 자존심 강한 두 천재의 대결
! 난이도: 골드 4
! 알고리즘 분류: 수학, 애드 혹
"""

# * 풀이 1
# ! 시간 초과

def cal_value(p, input_value):
    if p == 10:
        return int(input_value)
    
    value = 0
    len_value = len(input_value)
    for i in range(len_value):
        value += int(input_value[i]) * p ** (len_value - i - 1)
    
    return value

u, v = map(int, input().split())

A = input()
B = input()

val_A = cal_value(u, A)
val_B = cal_value(v, B)

if val_A > val_B:
    print("ras")
elif val_A < val_B:
    print("auq")
else:
    print("rasauq")