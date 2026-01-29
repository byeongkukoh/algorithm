# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
N = int(input())

result = 1
for i in range(1, N + 1):
	result = (result * i) % 1000000007
	
print(result)