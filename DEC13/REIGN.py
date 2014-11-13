def get_max_sum_subset(x):
    bestSoFar = 0
    bestNow = 0
    bestStartIndexSoFar = -1
    bestStopIndexSoFar = -1
    bestStartIndexNow = -1
    for i in xrange(len(x)):
        value = bestNow + x[i]
        if value > 0:
            if bestNow == 0:
                bestStartIndexNow = i
            bestNow = value
        else:
            bestNow = 0

        if bestNow > bestSoFar:
            bestSoFar = bestNow
            bestStopIndexSoFar = i
            bestStartIndexSoFar = bestStartIndexNow

    return bestSoFar, bestStartIndexSoFar, bestStopIndexSoFar

def main():
    t = int(raw_input());
    while t>0:
        N,K = map(int,raw_input().split());
        freq = [0]*N;
        A = map(int,raw_input().split());
        freq[0] = A[0];
        for i in range(1,N):
            freq[i] = freq[i-1] + A[i];
        mx = -10000000000;
        if K != 0:
            if (N-K-1 == 1):
                x1 = A[0:1];
                x2 = A[4:N];
                b1,s1,f1 = map(int,get_max_sum_subset(x1));
                b2,s2,f2 = map(int,get_max_sum_subset(x2));
                if b1 <= 0:
                    mn1 = 1;
                    for i in x1:
                        if(i < mn1):
                            mn1 = i;
                    b1 = mn1;
                if b2 <= 0:
                    mn2 = 1;
                    for i in x2:
                        if(i < mn2):
                            mn2 = i;
                    b2 = mn2;
                    
                #print ">",b1,s1,f1,b2,s2,f2;
                ans = (b1+b2);
                mx = ans;
            for k in range(1,N-K-1):
                #print m_idx;
                x1 = A[0:k];
                #print x1;
                x2 = A[k+K:N];
                #print x2;
                b1,s1,f1 = map(int,get_max_sum_subset(x1));
                b2,s2,f2 = map(int,get_max_sum_subset(x2));
                if b1 <= 0:
                    mn1 = 1;
                    for i in x1:
                        if(i < mn1):
                            mn1 = i;
                    b1 = mn1;
                if b2 <= 0:
                    mn2 = 1;
                    for i in x2:
                        if(i < mn2):
                            mn2 = i;
                    b2 = mn2;
                    
                #print ">",b1,s1,f1,b2,s2,f2;
                ans = (b1+b2);
                if ans > mx :
                    mx = ans;
            print mx;
        else:
            mx = -10000000000;
            for p in range(1,N):
                x1 = A[0:p];
                #print x1;
                x2 = A[p:N];
                #print x2;
                b1,s1,f1 = map(int,get_max_sum_subset(x1));
                b2,s2,f2 = map(int,get_max_sum_subset(x2));
                if b1 <= 0:
                    mn1 = 1;
                    for i in x1:
                        if(i < mn1):
                            mn1 = i;
                    b1 = mn1;
                if b2 <= 0:
                    mn2 = 1;
                    for i in x2:
                        if(i < mn2):
                            mn2 = i;
                    b2 = mn2;

                #print b1,s1,f1,b2,s2,f2;
                ans = (b1+b2);
                if ans > mx:
                    mx = ans;
            print mx;
        t = t-1;

#print get_max_sum_subset([-1]);

main();
    
        
