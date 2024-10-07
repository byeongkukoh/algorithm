"""
! 출처: https://www.acmicpc.net/problem/1181
! 문제: 단어 정렬
! 난이도: 실버 5
! 알고리즘 분류: 문자열 / 정렬
"""

# * 풀이 1

N = int(input())

words = set()
words_lens = []

for _ in range(N):
    words.add(input())
    
words = list(words)

for word in words:
    words_lens.append((word, len(word)))

words_lens.sort(key=lambda x: (x[1], x[0]))

for (word, _) in words_lens:
    print(word)