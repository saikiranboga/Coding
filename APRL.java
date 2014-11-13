import java.util.*;
import java.io.*;
public class APRL{
     
     
    public static void quicksort(int[] a, int left, int right) {
	if (right <= left) return;
	int i = partition(a, left, right);
	quicksort(a, left, i-1);
	quicksort(a, i+1, right);
    }
     
    // partition a[left] to a[right], assumes left < right
    private static int partition(int[] a, int left, int right) {
	int i = left - 1;
	int j = right;
	while (true) {
	    while (less(a[++i], a[right])) // find item on left to swap
		; // a[right] acts as sentinel
	    while (less(a[right], a[--j])) // find item on right to swap
		if (j == left) break; // don't go out-of-bounds
	    if (i >= j) break; // check if pointers cross
	    exch(a, i, j); // swap two elements into place
	}
	exch(a, i, right); // swap with partition element
	return i;
    }
    // is x < y ?
    private static boolean less(int x, int y) {
	return (x < y);
    }
     
    // exchange a[i] and a[j]
    private static void exch(int[] a, int i, int j) {
	int swap = a[i];
	a[i] = a[j];
	a[j] = swap;
    }
    public static void main(String[] args)throws IOException{
	InputStream inputStream = System.in;
	FastReader in = new FastReader(inputStream);

	int T = in.nextInt();
     
	for(int cas=0;cas<T;cas++){
	    int N = in.nextInt();
	    HashMap<Integer,Integer> bands_min = new HashMap<Integer,Integer>(N);
	    long total_sum = 0;
	    int i;
	    for(i=0; i<N; i++){
		int t = in.nextInt();
		int len = in.nextInt();
		total_sum += len;
		if(bands_min.containsKey(t) == false){
		    bands_min.put(t,len);
		}
		else{
		    int min = bands_min.get(t);
		    if(len < min){
			bands_min.put(t,len);
		    }
		}
	    }
	    int[] length_min_array = new int[100000];
	    i = 0;
	    for (Integer value : bands_min.values()) {
		length_min_array[i] = value;
		i++;
	    }
	    quicksort(length_min_array,0,i-1);
	    int j;
	    long sum = 0,sum_min = 0,lenth;
	    for(j=0;j<i;j++){
		lenth = length_min_array[j];
		sum += lenth*(j+1);
		sum_min += lenth;
	    }
	    sum += (total_sum - sum_min)*i;
	    System.out.println(sum);
	}
    }
} 
class FastReader
{
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    public FastReader(InputStream stream)
    {
	this.stream = stream;
    }
    public int next()
    {
	if (numChars == -1)
	    throw new InputMismatchException();
	if (curChar >= numChars)
	    {
		curChar = 0;
		try
		    {
			numChars = stream.read(buf);
		    } catch (IOException e)
		    {
			throw new InputMismatchException();
		    }
		if (numChars <= 0)
		    return -1;
	    }
	return buf[curChar++];
    }
    public int nextInt()
    {
	int c = next();
	while (isSpaceChar(c))
	    c = next();
	int sgn = 1;
	if (c == '-')
	    {
		sgn = -1;
		c = next();
	    }
	int res = 0;
	do
	    {
		if (c < '0' || c > '9')
		    throw new InputMismatchException();
		res *= 10;
		res += c - '0';
		c = next();
	    } while (!isSpaceChar(c));
	return res * sgn;
    }
    public static boolean isSpaceChar(int c)
    {
	return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
}