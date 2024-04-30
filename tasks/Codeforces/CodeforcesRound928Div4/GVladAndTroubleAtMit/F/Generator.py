
import random
t = 1
print(t)
for _ in range(t):
    n = int(1e2)
    print(n)
    for i in range(2, n + 1):
        print(random.randint(1, i-1), end=' ')
    print()
    print(''.join(random.choices('SCP', k=n)))

