#include <bits/stdc++.h>
#include <string.h>
using namespace std;

#define inf 1000000000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define VI vector<int>
#define PII pair<int, int>
#define all(v) (v.begin(), v.end())

int is_prime[1000010];

int main(){
	
	int n;
	
	for(int i=0; i<1000010; i++)
		is_prime[i] = 1;

	is_prime[0] = is_prime[1] = 0;

	int p;
	for(int i=2; i<1000010; i++){
		if(is_prime[i]==1){
			p = i+i;
			while(p<1000010){
				is_prime[p] = 0;
				p += i;
			}
		}
	}

	cin >> n;
	int a, b;
	for(int i=4; i<n; i++){
		a = i;
		b = n-i;
		if(is_prime[a]==0 && is_prime[b]==0){
			cout << a << " " << b << endl;
			break;
		}
	}

	return 0;
}