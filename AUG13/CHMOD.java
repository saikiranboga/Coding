import java.math.BigInteger;
import java.util.Scanner;
 
 
public class CHMOD {
 
    
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        BigInteger a[] = new BigInteger[100005];
        BigInteger b;
        int t;
        t = sc.nextInt();
        a[0] = BigInteger.ONE;
        for(int i=1; i<=t; i++){
	    b = sc.nextBigInteger();
	    a[i] = a[i-1].multiply(b);
	}
        t = sc.nextInt();
        int l,r;
	BigInteger m;
        for(int i=0;i<t;i++){
	    l = sc.nextInt();
	    r = sc.nextInt();
	    m = sc.nextBigInteger();
	    b = a[r];
	    b = b.divide(a[l]);
	    b = b.mod(m);
	    System.out.println(b);
	}
    }
}