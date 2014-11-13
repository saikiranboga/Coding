#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

#define PI 3.1415926
#define inf 1000000000

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)

#define gi(n) scanf("%d\n",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d\n",n)
#define pl(n) cout << n

//maimum length of the string
#define MLEN 10000000

// input string
string s;

//stores the string length
int N;

// represents the number of chars w.r.to which 
// the suffixes are sorted
int num_chars;

// bucket[i] stores the bucket number for 
// suffix starting at index i
// 
// special case:
// 		if `i` is greater than the max possible 
//		string index, its value is set to be -1
//		(similar to appending $ at the end)
int bucket[MLEN];

// helper bucket array to calc new buckets
int mod_bucket[MLEN];

class Suffix{
public:
	
	int idx; //suffix starting at index idx

	bool operator<(const Suffix& other) const{
		// overloading < operator for sorting position arrray.

		// used by:
		//	 in-built sort() function

		// Assumtions:
		//	 We have sorted suffixes till first `num_chars` chars
		// 	 and currently sorting suffixes w.r.t first 
		// 	 `2*num_chars` chars.

		// special case: 
		//	when we sort w.r.t the first char

		if(num_chars == 0){
			// special case

			// just compare the chars at the starting positions
			// and return the result
			return s[idx]<s[other.idx];
		}

		// if both the suffixes are not in the same bucket then 
		// return the comparision between the two buckets
		if(bucket[idx]!=bucket[other.idx]){
			return bucket[idx]<bucket[other.idx];
		}

		// we reach till here if both the suffixes are in the same bucket
		// then we just compare the next `num_chars` of both the suffixes
		return ( bucket[idx + num_chars] < bucket[other.idx + num_chars] );
	}

	bool operator==(const Suffix& other){
		// overloading == operator for comparing the
		// equality of two suffixes

		// used by:
		//		updateSuffixBuckets() function

		return !(*this<other) && !(other<*this);
	}

};

Suffix pos[MLEN];
int rank[MLEN];

bool updateSuffixBuckets(){
	bool all_diff_buckets = true;
	int cur_bucket=0, start = 0;
	rep(i,N){
		if(i!=0 && !(pos[i]==pos[i-1])){
			start = i;
			cur_bucket++;
		}
		if(start!=i){
			all_diff_buckets = false;
		}
		mod_bucket[pos[i].idx] = cur_bucket;
	}
	memcpy(bucket,mod_bucket,(N+10)*sizeof(int) );
	return all_diff_buckets;
}

void suffixArray(){

	rep(i,N){
		pos[i].idx = i;
		bucket[i] = bucket[i+N] = mod_bucket[i] = mod_bucket[i+N] = -1;
	}
	num_chars = 0;
	sort(pos,pos+N);
	bool all_diff_buckets = updateSuffixBuckets();

	for(num_chars=1; !all_diff_buckets; num_chars*=2){
		sort(pos,pos+N);
		all_diff_buckets = updateSuffixBuckets();
	}
	rep(i,N){
		rank[pos[i].idx] = i;
	}
}

// Begin of the O(n) longest common prefix algorithm
// Refer to "Linear-Time Longest-Common-Prefix Computation in Suffix
// Arrays and Its Applications" by Toru Kasai, Gunho Lee, Hiroki
// Arimura, Setsuo Arikawa, and Kunsoo Park.
int height[MLEN];
// height[i] = length of the longest common prefix of suffix pos[i] and suffix pos[i-1]
// height[0] = 0

// LCP(x,y) = minimum of { LCP(x,x+1) , LCP(x+1,x+2) ... LCP(y-1,y)
void getHeight(int n){
	for(int i=0; i<n; ++i)
		rank[pos[i].idx] = i;
	height[0] = 0;
	for(int i=0, h=0; i<n; ++i){
		if(rank[i] > 0){
			int j = pos[rank[i]-1].idx;
			while (i+h<n && j+h<n && s[i+h]==s[j+h]) h++;
			height[rank[i]] = h;
			if (h>0) h--;
		}
	}
}
// End of longest common prefixes algorithm


/*
Game Plan from TOPCODER

(1) At first step, we partition the suffixes based on their first symbol. We will have some buckets,
 and the first symbol of two suffixes which are in the same bucket are the same. we set t = 1.
(2) At each other step:
	- (*) Sort the suffixes based on their first 2t symbols,
	- Change the bucket boundaries so that all suffixes with the same initial 2t characters are in the same bucket.
	- Set t = 2*t.

If we do the (*) using an O(n log n) sort algorithm, we can construct the suffix array in O(n log^2 n). Although, there are better algorithms.
*/

int main(){
	
	getline(cin,s);
	N = s.sz;
		
	suffixArray();

	fu(i,0,N-1){
		pi(pos[i].idx);
	}
	return 0;
}