
import random
n = 200
print(n)
for _ in range(n):
    for y in range(7):
        print(''.join(random.choices('ABBBBBBBBBBBB', k=7)))
