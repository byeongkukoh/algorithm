"""
! 출처: https://www.acmicpc.net/problem/12018
! 문제: Yonsei TOTO
! 난이도: 실버 3
! 알고리즘 분류: 그리디, 정렬
"""

# * 풀이 1

n, m = map(int, input().split())

m_arr = []

for _ in range(n):
    P, L = map(int, input().split())
    app_arr = sorted(list(map(int, input().split())), reverse=True)
    
    if P < L:
        m_arr.append(1)
        continue
    
    m_arr.append(app_arr[L-1])

m_arr = sorted(m_arr)

count = 0
m_sum = 0

for i in m_arr:
    m_sum = m_sum + i
    if m_sum > m:
        break
    count += 1
    
print(count)