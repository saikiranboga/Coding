def modpow(b, pw, M):
	if(pw==0):
		return 1;
	if(pw==1):
		return b;

	ret = modpow(b, pw/2, M);
	ret = (ret*ret)%M;
	if(pw%2 > 0):
		ret = (ret*b)%M;
	return ret;


t = int(raw_input())
while(t > 0):
	N,M = map(int, raw_input().split())

	ans = 0;

	for i in range(1,N+1):
		ans = ( ans + ( modpow(i, 4, M)*(N/i) ) % M ) % M;

	print ans%M;

	t -= 1;