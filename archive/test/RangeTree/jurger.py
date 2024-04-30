
n, m = map(int, input().split())
xs = list(map(int, input().split()))
while m:
    line = input().split()
    if len(line) == 4:
        KD, OP, l, r = line
    else:
        KD, OP, l, r, w = line
        w = int(w)
    l = int(l)
    r = int(r)
    match KD:
        case 'Q':
            match OP:
                case 'MIN':
                    print(min(xs[l:r]))
        case _:
            match OP:
                case 'ADD':
                    # xs[l:r] += w
                    for i in range(l, r):
                        xs[i] += w
    m -= 1