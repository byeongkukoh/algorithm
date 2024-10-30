"""
! 출처: https://www.acmicpc.net/problem/30917
! 문제: A+B - 10 (제1편)
! 난이도: 브론즈 3
! 알고리즘 분류: 수학 | 구현 | 브루트포스 | 사칙연산
"""

for a in range(1, 10):
    print(f"? A {a}")
    
    if input() == "1":
        break

for b in range(1, 10):
    print(f"? B {b}")
    
    if input() == "1":
        break

print(f"! {a+b}")