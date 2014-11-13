import collections
import hashlib
import fractions

def count(s):
    
    hsh = {}
    N = len(s)

    for i in s:
        hsh[ hashlib.md5(str(i)).digest()] = 1
        
    R = [[None]*(N+1) for _ in range(2)]
    s = "@" + s + "#"
    
    for j in range(0,2):
        R[j][0] = rp = 0
        i = 1
        while i <= N:
            while s[i-rp-1] == s[i+j+rp]:
                rp += 1
            R[j][i] = rp
            k = 1
            while ( (R[j][i-k] != (rp-k)) and (k<rp) ):
                R[j][i+k] = min(R[j][i-k], rp-k)
                k += 1
            rp = max(rp-k, 0)
            i += k

    s = s[1:N+1]
    for i in range(1,N+1):
        for j in range(0,2):
            for rp in range(R[j][i], 0, -1):
                hsh[ hashlib.md5(str(s[(i-rp-1):(i-rp-1)+(2*rp+j)])).digest() ] = 1
    return len(hsh)

def main():
    s = str(raw_input())
    N = int(raw_input())
    T = len(s)

    n = count(s)
    k = N
    k_2 = k/2
    if(k%2 == 0):
        ans = k*pow(n,k_2)
        ans = ans + k*pow(n,k_2+1)
        
        tmp = 0
        for p in range(1,k+1):
            tmp = tmp + pow(n,fractions.gcd(k,p))

        ans = ans + (2*tmp)
        ans = ans/(4*k)
        print ans
    else:
        ans = k*pow(n,(k+1)/2)
        
        tmp = 0
        for p in range(1,k+1):
            tmp = tmp + pow(n,fractions.gcd(k,p))

        ans = ans + tmp
        ans = ans/(2*k)
        print ans

main()
