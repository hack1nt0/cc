import random
import sys

N = 1e5
M = 1e5
n = random.randint(N, N)
m = random.randint(M, M)
print(n, m)

for i in range(n):
    print(random.randint(-10, 10), end=' ')
print(flush=True)


def gen(KD):
    L = random.randint(0, n - 1)
    R = random.randint(L + 1, n)
    match KD:
        case 'Q':
            OP = ['MIN', 'MAX', 'SUM'][random.randint(0, 0)]
            print(KD, OP, L, R, flush=True)
        case 'M':
            W = random.randint(0, 10)
            OP = ['ADD', 'MUL', 'ASS'][random.randint(0, 0)]
            print(KD, OP, L, R, W, flush=True)
# print(3)
# gen('M')
# gen('M')
# gen('Q')

# np = 2
# print(np)
# for i in range(np):
#     KD = ['Q', 'M'][(i + 1) % 2]
#     # KD = 'Q'
#     L = random.randint(0, n - 1)
#     R = random.randint(L + 1, n)
#     match KD:
#         case 'Q':
#             OP = ['MIN', 'MAX', 'SUM'][random.randint(0, 0)]
#             print(KD, OP, L, R)
#         case 'M':
#             W = random.randint(0, 10)
#             OP = ['ADD', 'MUL', 'ASS'][random.randint(0, 0)]
#             print(KD, OP, L, R, W)


for i in range(m):
    KD = ['Q', 'M'][random.randint(0, 1)]
    gen(KD)

print('G D', file=sys.stderr)