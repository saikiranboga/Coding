import java.util.*;
import java.lang.*;
import java.math.*;

class Main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t,n,m;
		t = sc.nextInt();

		int[][] comb = new int[11][11];

		for(n = 0; n <= 10; n++){
			int nCk = 1;
			for(int k = 0; k <= n; k++){
				comb[n][k] = nCk;
				nCk = nCk * (n-k) / (k+1);
			}
		}

		while(t!=0){
			
			n = sc.nextInt();

			BitSet[] ar = new BitSet[n];
			int[] ar_sizes = new int[n];
			BigInteger[] cnts = new BigInteger[n+1];

			BigInteger tmp = BigInteger.valueOf(0);

			for(int i=0;i<=n;i++){
				cnts[i] = tmp;
			}

			BigInteger prod = BigInteger.valueOf(1);

			int sz,x,block,in_block;
			String line;

			sc.nextLine();
			for(int i=0; i<n; i++){
				ar[i] = new BitSet(0);
				sz = 0;
				line = sc.nextLine();
				String[] shirts = line.split(" ");
				sz = shirts.length;
				for(int j=0; j<sz; j++){
					x = Integer.parseInt(shirts[j]);
					ar[i].set(x);
				}
				ar_sizes[i] = sz;
				prod = prod.multiply(BigInteger.valueOf(sz));
			}

			int mx = (1<<n)-1;

			for(int msk=3; msk<=mx; msk++)
			{
				int ind = 0;
				int mask = msk;
    			boolean first_seen = false;
    			BitSet accumulate = new BitSet(0);
    			int n_sets = 0;
    			BigInteger cur_prod = prod;

    			while(mask>0){
    				if( (mask&1) == 1){
    					n_sets += 1;
    					if(first_seen==false){
    						accumulate = (BitSet)ar[ind].clone();
    						first_seen = true;
    					}
    					accumulate.and( ar[ind] );
    					cur_prod = cur_prod.divide( BigInteger.valueOf(ar_sizes[ind]) );
    				}
    				ind++;
    				mask = mask/2;
    			}
    			int intersxn = accumulate.cardinality();
    			cur_prod = cur_prod.multiply(BigInteger.valueOf(intersxn) );
    			cnts[n_sets] = cnts[n_sets].add(cur_prod);
    		}

			BigInteger ans = prod;
			for(int i=2; i<=n; i++){
				System.out.println(i + ": " + cnts[i]);
				if(i%2==0)
					ans = ans.subtract(cnts[i]);
				else
					ans = ans.add(cnts[i]);
			}

			ans = ans.mod(BigInteger.valueOf(1000000007));

			System.out.println(ans);
			t--;
		}
	}
}