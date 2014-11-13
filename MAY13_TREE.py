#!/usr/bin/python
MOD = 1000000007

def main():

    n,k = map(int,raw_input().split(" "))
    ans = 1;

    if(n == 1 and k != 1):
        print "0";

    elif(n == 1 and k == 1):
        print "1";

    elif(k == 1):
        for i in range(1,n-1):
            ans = (ans*n)%MOD;

        ans = ans%MOD;
        print ans;

    elif(k == 2):

        #n^(n-2) * (n-1)^n * 4^(n-1);

        for i in range(1,n-1):
            ans = (ans*n)%MOD;

        for i in range(1,n+1):
            ans = (ans*(n-1))%MOD;

        for i in range(1,n):
            ans = (ans*4)%MOD;
        ans = ans%MOD;

        print ans;

    elif(k == 3):
        # n^(n-2) * (n-1)^(2*n) * 3^(3*n-2);
        for i in range(1,n-1):
            ans = (ans*n)%MOD;

        for i in range(1,2*n+1):
            ans = (ans*(n-1))%MOD;
    
        for i in range(1,3*n-1):
            ans = (ans*3)%MOD;
    
        ans = ans%MOD;
        print ans;
if __name__:

    main()
