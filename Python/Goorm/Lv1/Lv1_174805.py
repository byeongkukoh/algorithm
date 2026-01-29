# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
N, K = input().split()
arr = input().split()

result = [item for item in arr if K not in item]

print(len(result))