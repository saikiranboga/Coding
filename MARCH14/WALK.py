t = int(raw_input());
while(t):
    n = int(raw_input());
    a = map(int,raw_input().split());
    ans = a[n-1];
    for i in range(n-2,-1,-1):
        ans += 1;
        if(ans < a[i]):
            ans = a[i];
    print ans;
    t -= 1;