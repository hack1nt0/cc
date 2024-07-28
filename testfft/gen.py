import random

n = random.randint(1, 10)
m = random.randint(1, 10)
x1 = random.choices(range(10), k=n)
x2 = random.choices(range(10), k=m)
print(n, m)
print(" ".join(map(str, x1)))
print(" ".join(map(str, x2)))

