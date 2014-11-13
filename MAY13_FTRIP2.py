#!/usr/bin/python

pascal = [[0 for i in xrange(1001)] for j in xrange(1001)]

for i in range (0,1001):
    pascal[i][0]=1
    pascal[i][i]=1
for i in range (1,1001):
    for j in range (1,1001):
        if(i != j):
            pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1]

t = input()

for _ in range(0,t):
    s,n,m,k = map(int,raw_input().split(' '))
    num = 0.000000000000;
    denom = float(pascal[s-1][n-1]);
    if( s == n ):
        print "1.000000000000";
        continue;
    if( k > n ):
        print "0.000000000000";
        continue;
    if( m > n ):
        temp = n;
    else:
        temp = m;
    for i in range(k,temp):
        num += ((pascal[m-1][i])*(pascal[s-m][n-i-1]));
    print "%.12f" % (float(num/denom))

