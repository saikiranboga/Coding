import java.util.*;import java.io.*;import java.math.*;
public class Main{public static void main(String[] args) throws Exception {
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	String st=br.readLine();
	int s1=st.indexOf(" "),n=Integer.parseInt(st.substring(0,s1)),d=Integer.parseInt(st.substring(s1+1,st.length()));
	while(!(n==0&&d==0)){
		BigInteger ans=BigInteger.valueOf(1);
		for(int i=0;i<d;i++)ans = ans.multiply(BigInteger.valueOf(n));
		System.out.println(ans.toString());
		st=br.readLine();
		s1=st.indexOf(" ");
		n=Integer.parseInt(st.substring(0, s1));
		d=Integer.parseInt(st.substring(s1+1,st.length()));
    }
}
}