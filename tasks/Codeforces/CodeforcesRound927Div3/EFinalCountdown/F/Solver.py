import sys
sys.set_int_max_str_digits(0)

def solve(it):
    n = int(input())
    digits = input()
    ret = 0
    prefix = 0
    ptr = 0
    while digits[ptr] == '0': ptr += 1
    while ptr < n:
        d = int(digits[ptr])
        changes = n - ptr
        ret += (prefix * 9 + d) * changes
        prefix = prefix * 10 + d
        ptr += 1
    print(ret)

for it in range(int(input())):
    solve(it)
