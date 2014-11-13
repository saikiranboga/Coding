import sys;
inp = sys.stdin.read().split("\n");
t = len(inp);
i = 0;
while(t):
	n = int(inp[i]);
	ans = 0;
	if(n==0):
		ans = 0;
	elif(n==1):
		ans = 1;
	else:
		ans = (2*n-2);
	print ans;
	t -= 1;
	i += 1;