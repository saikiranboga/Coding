import java.util.*;
import java.lang.*;
import java.math.*;

class UJ
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int n,m;
		n = sc.nextInt();
		m = sc.nextInt();
		while( !(n==0 && m==0) ){
			BigInteger res = BigInteger.valueOf(n);
			res = res.pow(m);
			System.out.println(res);
			n = sc.nextInt();
			m = sc.nextInt();
		}
	}
}