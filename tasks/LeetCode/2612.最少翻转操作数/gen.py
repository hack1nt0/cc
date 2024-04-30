
import random
n = int(1e5)
p = random.randint(0, n - 1)
nb = random.randint(0, n)
k = random.randint(n / 2, n)
print(n, p, nb, k)
for _ in range(nb):
    print(random.randint(0, n - 1), end=' ')
print()