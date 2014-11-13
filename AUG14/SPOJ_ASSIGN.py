_pc = []
for i in range(256):
    c = 0
    while i:
        # clear last set bit
        i &= i-1
        c += 1
    _pc.append(c)

def popcount(i):
    "Return number of bits set."
    result = 0
    while i:
        result += _pc[i & 0xff]
        i >>= 8
    return result

def perm(a,num):
    "Return permanent of 0-1 matrix.  Each row is an int."
    result = 0
    n = num

    for s in range(1 << n):
        prod = 1
        for row in a:
                if(row!=0):
                    prod *= popcount(row & s)
        if popcount(s) & 1:
            result -= prod
        else:
            result += prod
    if n & 1:
        result = -result
    return result

def matrix2ints(a):
    return [int("".join(map(str, row)), 2)
            for row in a]

def matrix_perm(a,num):
    "Return permanent of 0-1 matrix."
    return perm(matrix2ints(a), num)

def main():
    n = int(raw_input());
    a = [[0 for cols in range(101)] for rows in range(101)]
    for i in range(n):
        line = map(int,raw_input().split(' '));
        for j in line:
            a[i][j] = 1;

    print matrix_perm(a,n)

main()