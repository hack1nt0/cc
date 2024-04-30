from sys import stdin, stdout, stderr

def W(x):
    print(x, flush=True)
    stdout.flush()

def V(x):
    print(x, flush=True, file=stderr)
    stderr.flush()

nt = int(stdin.readline())
for it in range(nt):
    n = int(stdin.readline())

    V(n)

    S = list(map(lambda c: int(c), stdin.readline().split()))

    V(S)
    
    W(n)
    for s in S:
        W(s)
    
    ST = set(S)
    