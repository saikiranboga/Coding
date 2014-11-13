import java.util.*;
import java.lang.*;
import java.math.*;

class Main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int n, x;
		n = sc.nextInt();
		BigInteger[] A = new BigInteger[n];

		BigInteger sumLeft = BigInteger.valueOf(0); // [variable]
		BigInteger sumRight = BigInteger.valueOf(0); // [variable]

		int mid = n/2;
		for(int i=0; i<n ;i++){
			x = sc.nextInt();
			A[i] = BigInteger.valueOf(x);
			if(i<mid)
				sumLeft = sumLeft.add(A[i]);
			else
				sumRight = sumRight.add(A[i]);
		}

		ArrayList<Integer> lefts = new ArrayList<Integer>();
		int lt, rt;
		if(n > 100)
			rt = n/2+40;
		else
			rt = n;
		int totSum = 0;
		do{
			
			lt = getIndexToShift(A, sumLeft, sumRight, n);

			if( (lt==-1) || ((totSum+(n-lt))>2*n ) )
				break;

			if( lt != -1 ){
				
				totSum += (rt-lt);

				sumLeft = sumLeft.subtract(A[lt]);
				sumLeft = sumLeft.add(A[mid]);
				sumRight = sumRight.subtract(A[mid]);
				sumRight = sumRight.add(A[lt]);

				//System.out.println(sumLeft + " " + sumRight + "--");
				shift(A, lt, rt);
				lefts.add(lt+1);
			}

		}while( (lt != -1) && (totSum<=2*n) );

		int sz = lefts.size();
		
		System.out.println(sz);
		for(int i=0;i<sz;i++)
			System.out.println(lefts.get(i) + " " + rt);
	}

	public static int getIndexToShift(BigInteger[] A, BigInteger lsum, BigInteger rsum, int n){

		BigInteger tmpSumLeft, tmpSumRight, absTmp, absMin, absDiffOrig;

		absMin = lsum.subtract(rsum);
		absMin = absMin.abs();

		int mid = n/2;
		int left = -1; // which left to choose. [variable]

		for(int i=mid-1;i>=0;i--){
			tmpSumLeft = lsum.subtract(A[i]);
			tmpSumLeft = tmpSumLeft.add(A[mid]);

			tmpSumRight = rsum.subtract(A[mid]);
			tmpSumRight = tmpSumRight.add(A[i]);

			absTmp = tmpSumLeft.subtract(tmpSumRight);
			absTmp = absTmp.abs();

			if( absTmp.compareTo(absMin) < 0 ){
				left = i;
				absMin = absTmp;
				break;
			}
		}
		return left;
	}

	public static void shift(BigInteger[] A, int ind, int n){
		// shifts one elemet circularly to left

		BigInteger backup = A[ind];
		for(int i=ind;i<n-1;i++)
			A[i] = A[i+1];
		A[n-1] = backup;
	}
}