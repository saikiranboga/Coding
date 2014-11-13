#!/usr/bin/python

def main():
    t = input();

    for _ in range(0,t):
        s,n,m,k = map(int,raw_input().split(' '))
        prod = float(1.000000)
        num = float(0)
        denom = float(0)
        num += float(prod)

        for i in range(1,k):
            if(s-m-n+i+1 > 0):
                #prod *= ((m-1-i)/(i+1))*((n-i-1)/(s-m-n+i+2))
                prod *= ((float)(m-i)/(i))*((float)(n-i)/(float)(s-m-n+i+1))
                num += float(prod)
        denom = num

        for i in range(k,m):
            if((s-m-n+i+1) > 0):                
                #prod *= ((m-1-i)/(i+1))*((n-i-1)/(s-m-n+i+2))
                prod *= ((float)(m-i)/(i))*((float)(n-i)/(float)(s-m-n+i+1))
                denom += float(prod)

        if((m-k-1 == s-n) or (s == n)):
            print "1.00000000"
        else:
            print "%.12f" %(1-(num/denom))      

if __name__:

    main()
