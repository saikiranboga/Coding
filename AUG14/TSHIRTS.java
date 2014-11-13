import java.io.*;
import java.util.*;
import java.util.Arrays;
import java.lang.*;
import java.math.*;

class Main
{

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in) );
		//BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out) );

		long MOD = 1000000007;
		int t = Integer.parseInt(br.readLine());
		String line = null;
		String[] tmpShirts;
		while(t-->0){
			// [read input] [initialization]
			int n = Integer.parseInt(br.readLine());

			int[][] shirts = new int[n][101];
			int[] tot = new int[n];

			for(int i=0;i<n;i++){
				line = br.readLine();
				tmpShirts = line.split(" ");

				tot[i] = tmpShirts.length;
				for(int j=0; j<tot[i]; j++)
					shirts[i][j] = Integer.parseInt(tmpShirts[j]);
				Arrays.sort(shirts[i], 0, tot[i]);
			}

			// [intialization]
			int idx;
			int mx = 1<<n;
			long[][] f = new long[mx][101];
			long[][][] calc = new long[mx][n][101];

			for(int i=0;i<mx;i++){
				for(int j=0;j<101;j++)
					f[i][j] = 0;
				for(int j=0;j<n;j++)
					for(int k=0;k<101;k++)
						calc[i][j][k] = 0;
			}

			// [solve]
			f[0][0] = 1;
			for(int mask=0; mask<mx; mask++){
				for(int col=0; col<101;col++){
				
					for(int cur=0;cur<n;cur++){
						if( ( (mask & (1<<cur) ) > 0) ){
							idx = Arrays.binarySearch(shirts[cur], 0, tot[cur], col);
							if( ( (idx<tot[cur]) && (idx>=0) && (shirts[cur][idx]==col)) ){
								for( int i=col; i>=0; i=(((i+1)&i)-1) )
									f[mask][col] = (f[mask][col] + calc[mask][cur][i])%MOD;
							}
						}
					}

					if( (f[mask][col]==0) )
						continue;

					for(int cur=0; cur<n; cur++){
						if( ( (mask & (1<<cur) ) > 0) )
							continue;
						idx = upper_bound(shirts[cur], 0, tot[cur], col);
						if( ( (idx<tot[cur]) && (idx>=0)) )
							for(int i=shirts[cur][idx]; i<101; i=(i+1)|i )
								calc[(mask|(1<<cur))][cur][i] += f[mask][col];
					}

				}
			}
			long combs = 0;
			for(int i=0; i<101; i++)
				combs = (combs + f[mx-1][i])%MOD;
			System.out.println(combs);
			
		}
	}

    public static int upper_bound(int[] arr, int start, int length, int key) {
        int len = length;
        int lo = start;
        int hi = len-1;
        int mid = (lo + hi)/2;
        while (true) {
            if ( ( (arr[mid]==key) || (arr[mid]<key) ) ) {
                lo = mid+1;
                if (hi < lo)
                    return (mid<(len-1))?(mid+1):(-1);
            } else {
                hi = mid-1;
                if (hi < lo)
                    return mid;
            }
            mid = (lo + hi)/2;
        }
    }

}