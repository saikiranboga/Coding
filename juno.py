MOD = 1000000007
 
def modpow(base, exp):
    base %= MOD;
    result = 1;
    while (exp > 0):   
        if (exp & 1):
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;    
    return result;
 
def main():
    P = [0]*200;
    Q = [0]*200;
    A = [0]*2;
    B = [0]*2;
    C = [0]*2;
    M = [0]*2;
    for i in range(int(raw_input())):
 
        V,N = map(int,raw_input().split());
        P[0],P[1],A[0],B[0],C[0],M[0] = map(int,raw_input().split());
        Q[0],Q[1],A[1],B[1],C[1],M[1] = map(int,raw_input().split());

        if(V%MOD == 0):
            print "0"
        else:
            ans = 1;
            temp = (P[0]*M[1]+Q[0]);
            if(temp != 0):
                ans *= temp;
                temp = (P[1]*M[1]+Q[1]);
            if(temp != 0):
                ans *= temp;
 
            for i in range(2,N):
                P[i] = ( (A[0]*A[0]*P[i-1]) + ( B[0]*P[i-2] ) + C[0])%M[0];
                Q[i] = ( (A[1]*A[1]*Q[i-1]) + ( B[1]*Q[i-2] ) + C[1])%M[1];
                temp = ( P[i]*M[1] + Q[i])
                if(temp != 0):
                    ans *= temp;
 
            print modpow(V,ans%(MOD-1))
        
main()
