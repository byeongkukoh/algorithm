# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
user_input = input()
am, cm, bm = map(int, user_input.split())

gcd = 1;
now = 2;
while (now <= (am * bm) and now <= cm):
	if ((am * bm) % now == 0 and cm % now == 0):
		gcd = now
	now += 1

print(f"{(am * bm) // gcd} {cm // gcd}")