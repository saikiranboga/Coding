def val(n):
	ret = n*(n+1)*(2*n+1)*(3*n*(n+1) - 1)
	return int(ret/30);

def main():
	t = int(raw_input())
	while(t > 0):
		N,M = map(int, raw_input().split())

		il = 0;
		ih = 0;
		ans = 0;
		while (ih < N):
			il = ih+1;
			q = int(N/il);
			ih = int(N/q);
			if(ih==il):
				ans = ans + pow(il, 4)*q;
			else:
				ans = ans + (val(ih)-val(il-1))*q;
		print ans%M;
		t -= 1;

if __name__=="__main__":
	main()