import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

public class Solution
{
	public static void main(String args[]) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in) );
		BigInteger n;
		String s = br.readLine();
		n = new BigInteger(s);

		BigInteger tmp = n.mod(BigInteger.valueOf(4));
		if( (tmp.compareTo(BigInteger.valueOf(0)) == 0) ){
			System.out.println(4);
		}
		else{
			System.out.println(0);
		}
	}
}