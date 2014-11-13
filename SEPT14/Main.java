import java.io.*;
import java.util.*;
import java.util.Arrays;
import java.lang.*;
import java.math.*;

class Main
{

	public static void main(String[] args) throws IOException{
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in) );
		Scanner sc = new Scanner(System.in);

		//int t = Integer.parseInt(br.readLine());
		long t = sc.nextLong();

		String line = null;
		String[] tmp;

		while(t-->0){
			
			long N,M;
			//line = br.readLine();
			//tmp  = line.split(" ");
			//N    = Integer.parseInt(tmp[0]);
			//M 	 = Integer.parseInt(tmp[1]);
			N = sc.nextLong();
			M = sc.nextLong();
			
			long il = 0;
			long ih = 0;
			long q;
			BigInteger ans = BigInteger.ZERO;
			while (ih < N){
				il = ih+1;
				q  = N/il;
				ih = N/q;
				if(ih==il){
					ans = ans.add( BigInteger.valueOf((long)(Math.pow(il, 4)*q)) );
				}
				else{
					BigInteger tp = val(ih).subtract( val(il-1) );
					tp = tp.multiply( BigInteger.valueOf(q) );
					ans = ans.add( tp );
				}
			}
			ans = ans.mod( BigInteger.valueOf(M) );
			System.out.println(ans);
		}
	}

	public static BigInteger val(long n){
		BigInteger ret = BigInteger.valueOf(n);
		ret = ret.multiply( BigInteger.valueOf((n+1)) );
		ret = ret.multiply( BigInteger.valueOf((2*n+1)) );

		BigInteger tmp = BigInteger.valueOf(n); // (3*n*(n+1) - 1)
		tmp = tmp.multiply( BigInteger.valueOf((3*(n+1))) );
		tmp = tmp.subtract( BigInteger.valueOf(1) );

		ret = ret.multiply( tmp );
		ret = ret.divide( BigInteger.valueOf(30) );
		return ret;
	}
}
/*
4
4 10000
373
5 10000
999
100000000 100000
86623
10 1000000
26449
*/