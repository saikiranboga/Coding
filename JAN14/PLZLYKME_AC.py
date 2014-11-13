p = 31;
q = 32;
a = [[0]*(p+1) for i in range(q+1)];

a[1][1] = 1;

for i in range(2, p+1):
	a[i][1] = 1;
	a[i][i] = 1;	

for i in range(3, p+1):
	for j in range(2, i):
		a[i][j] = a[i-1][j-1] + a[i-1][j];

#
#for i in range(1, p+1):
#	for j in range(1, i+1):
#		print a[i][j],'\t'
#	print "\n";

T = int(raw_input())

while T != 0:
	ans = 1;
	L, D, S, C = map(int, raw_input().split());
	if(D >= 30):
		print "ALIVE AND KICKING";
	else:
		_C = C;
		for j in range(2, D+1):
			ans = ans + ( _C*a[D][j] );
			_C = _C*C;
		ans = ans*S;
		if(ans >= L):
			print "ALIVE AND KICKING";
		else:
			print "DEAD AND ROTTING";
	T -= 1;