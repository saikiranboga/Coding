#!/usr/bin/python
from operator import mul

nCk = lambda n,k: int(round(
    reduce(mul, (float(n-i)/(i+1) for i in range(k)), 1)
))

if __name__ == "__main__":

    T = int(raw_input());
    for i in range(T):
        args = raw_input().split(" ");
        S = int(args[0]);
        N = int(args[1]);
        M = int(args[2]);
        K = int(args[3]);

        if(N-1 >= K):
            if(M-1 >= K):
                ans = (nCk(M-1,K)*nCk(S-K-1,N-K-1))/float(nCk(S-1,N-1));
                if(S == N):
                    print "1.000000"
                else:
                    print ans
                continue;
        print "0.000000"
