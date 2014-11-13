#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;

#define ll long long

#define fore(i, l, r) for(int i = (l); i < (r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define ford(i, up, bot) for(int i = (up); i > (bot); --i)
#define fordi(i, up, bot) ford(i, up, bot-1)

#define pb push_back
#define mp make_pair

typedef pair<int, int> pt;

int primes[100000];
int size_primes;
void gen_primes(){
	//31622.7 .... is square root of 10^9
	int is_prime[31624];

	for(int i=0; i<31624; i++)
		is_prime[i] = 1;

	is_prime[0] = 0;
	is_prime[1] = 0;

	int i, p = 2;
	int prime_ind = 0;
	while(p < 31623){
		//cout << p << endl;
		primes[prime_ind] = p;
		prime_ind++;
		i = 2*p;
		while(i<=31623){
			is_prime[i] = 0;
			i += p;
		}
		for(i=p+1; i<31624; i++){
			if(is_prime[i]==1){
				p = i;
				break;
			}
		}
		if(i==31624)
			break;
	}
	size_primes = prime_ind;
}

int sieve[1000010];
void find_sieve(int lo, int hi){
	if(lo==1)
		lo++;
	for(int i=0;i<1000010;i++)
		sieve[i] = 1;
	int sq = sqrt(hi);
	int p;
	for(int i=0;i<size_primes;i++){
		p = primes[i];
		if(p*p>hi)
			continue;
		else{
			int mn = (lo/p)*p;
			if(mn<lo)
				mn += p;
			if(mn==p)
				mn += p;
			while(mn<=hi){
				sieve[mn-lo] = 0;
				mn += p;
			}
		}
	}
	for(int i=lo;i<=hi;i++){
		if(sieve[i-lo]==1)
			cout << i << endl;
	}
	cout << endl;
}

int main(){	
	gen_primes();
	int t;
	cin >> t;
	int m,n;
	while(t--){
		cin >> m >> n;
		find_sieve(m,n);
	}

	return 0;
}