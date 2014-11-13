
MOD = 1000000007;

def gcd(a,b):
	if(b==0):
		return a;
	return gcd(b,a%b);

def lcm(a,b):
	return (a*b)/gcd(a,b);

t = int(raw_input());
while(t):
    n = int(raw_input());
    pos = map(int,raw_input().split());
    
    vis = [False]*n;

    for i in range(0,n):
    	pos[i] = pos[i]-1;

    ans = 1;

    for i in range(0,n):
    	cycle_len = 0;
    	if(vis[i]==True):
    		continue;
    	cycle_start = pos[i]
    	next = cycle_start;
    	while(True):
    		cycle_len += 1;
    		vis[next] = True;
    		next = pos[next];
    		if(next==cycle_start):
    			break;
    	ans = lcm(ans, cycle_len);

    print(ans%MOD);

    t -= 1;