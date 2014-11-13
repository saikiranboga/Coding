import java.util.*;
import java.io.*;
import java.math.BigInteger;
 
public class MAY13_WITMATH{
  public static long t;
  public static void main(String[] args) {
      BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
      t = Long.parseLong(in.readLine());

      for(int cas=0;cas<t;cas++){	  
	  BigInteger N = new BigInteger(in.readLine());
	  System.out.println(N.isProbablePrime(1000000000));
      }
  }
}