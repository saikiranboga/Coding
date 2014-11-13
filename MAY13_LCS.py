#!/usr/bin/python

def LCSLength( X, Y ):
    
    m = len(X)
    n = len(Y)
    C = [[0 for i in range(n+1)] for j in range(m+1)]

    for i in range(1,m+1):
        for j in range(1,n+1):
            if(X[i-1] == Y[j-1]): 
                C[i][j] = C[i-1][j-1] + 1
            else:
                C[i][j] = max(C[i][j-1], C[i-1][j])
    if(C[m][n] == m or C[m][n] == n):
        return "YES"
    else:
        return "NO"

if __name__ == "__main__":

    t = int(raw_input(),10);
    while(t):
        inpt = raw_input().split(" ")
        print LCSLength(inpt[0],inpt[1])
        t = t-1
