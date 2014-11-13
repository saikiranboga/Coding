n = int(raw_input());

if(n<13):
	print(0);
else:
	if(n==13 or n==14):
		print(1);
	else:
		mn = 1;
		mx = n-13;
		ans = 0;
		for i in range(mx+1):
			x = i;
			if(x%2 == 0):
				cur = 1;
				x = x / 2;
				for j in range(5):
					cur = cur*(x+j+1);
				cur = cur/120;
				ans = (ans + cur) % 1000000007;
		print ans;