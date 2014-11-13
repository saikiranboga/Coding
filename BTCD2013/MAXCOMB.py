MOD = 1000000007
cases = int(raw_input())
while cases != 0:
    n,m = map(int,raw_input().split(" "))
    A=[1]*n # Number of ways of being at digit i and never being to min or max
    B=[0]*n # number of ways with minimum being observed
    C=[0]*n # number of ways with maximum being observed
    D=[0]*n # number of ways with both being observed
    A[0]=0 # Cannot start with 0
    A[n-1]=0 # Have seen max so this 1 moves from A to C
    C[n-1]=1 # Have seen max if start with highest digit
    t=0
    for k in range(m-1):
        A2=[0]*n
        B2=[0]*n
        C2=[0]*n
        D2=[0]*n
        for i in range(1,n-1):
            A2[i]=A[i+1]+A[i-1]
            B2[i]=B[i+1]+B[i-1]
            C2[i]=C[i+1]+C[i-1]
            D2[i]=D[i+1]+D[i-1]
        print A
        print B
        print C
        print D
        print "--"
        B2[0]=A[1]+B[1]
        C2[n-1]=A[n-2]+C[n-2]
        D2[0]=C[1]+D[1]
        D2[n-1]=B[n-2]+D[n-2]
        A=A2
        B=B2
        C=C2
        D=D2
#        for i in range in D2
        print A
        print B
        print C
        print D
        print "--"
        x = sum(d for d in D2)
        t = (t+x)%MOD
    print (t%MOD)
    cases -= 1
