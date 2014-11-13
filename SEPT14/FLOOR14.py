def val(n):
	ret = n*(n+1)*(2*n+1)*(3*n*(n+1) - 1)
	return int(ret/30);

def main():
	t = int(raw_input())
	while(t > 0):
		N,M = map(int, raw_input().split())

		imax = N;
		imin = N/2;
		rem = N;
		cr = 2;
		ans = 0;
		summa = 0;

		while(rem>0):

			while(rem>0 and imax-imin>5):
				summa = (cr-1) * ( val(imax) - val(imin) );
				ans  = ans + summa;
				cr   += 1
				rem -= (imax-imin);
				imax = imin;
				imin = N/cr;
				if(imin==imax):
					imin -= 1;

			if(rem <= 0):
				break;
			print cr, imin, imax;
			if(rem <=1000000):
				for i in range(1, imax+1):
					ans = ans + pow(i, 4)*(N/i);
				break;
			for i in range(imin+1, imax+1):
				ans = ans + pow(i,4)*int(N/i);
			cr += 1;
			rem -= (imax-imin);
			imax = imin;
			imin = N/cr;
			if(imin == imax):
				imin -= 1;

		print ans%M;

		t -= 1;

if __name__=="__main__":
	main()