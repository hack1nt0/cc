
import random
import string
print(1)
MAX = int(2e5)
print(MAX, MAX)
print(''.join(random.choices(string.ascii_letters, k=MAX)))
for _ in range(MAX):
	R = random.sample(range(1, MAX + 1), k=2)
	print(min(R), max(R))
