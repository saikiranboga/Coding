M = 1000000007;
def power(a, b):
    if b == 0:
        return 1;
    elif b == 1:
        return a;
    else:
        t = ( power(a,b/2) )%M;
        if b%2 == 1:
            return (((t*t)%M)*a)%M;
        else:
            return (t*t)%M;
t = int(raw_input());
while t != 0:
    n,m,q,k = map(int,raw_input().split(" "));
    if n == 1 or  m <= q:
        print 0;
    else:
        ans1 = ( (power(q+1,n)%M) - (2*power(q,n))%M + (power(q-1,n))%M )%M;
        ans = ( (m-q)*(ans1) )%M;
        print ans;
    t -= 1;
