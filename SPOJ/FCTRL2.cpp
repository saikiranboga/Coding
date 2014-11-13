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

int fact[1000];
int temp[1000];
void small_factorial(int n){
	memset(fact,0,sizeof(fact));

	fact[0] = 1;
	int sz = 0;
	int mul,tmp,id,mul_d;
	for(int i=2;i<=n;i++){
		mul = i;
		memset(temp,0,sizeof(temp));
		for(int j=0;j<=sz;j++){
			tmp = fact[j]*mul;
			id = j;
			int carry = 0;
			while(tmp){
				temp[id] = temp[id] + (tmp%10) + carry;
				carry = temp[id]/10;
				temp[id] = temp[id]%10;
				tmp = tmp/10;
				id++;
			}
			if(carry>0)
				temp[id++] = carry;
			if(id>sz)
				sz = id-1;
		}
		memcpy(fact, temp, sizeof(fact));
	}

}

int main(){	

	int t,n;
	cin >> t;

	while(t--){
		cin >> n;
		int n2 = n;
		if(n==100)
			n = 99;
		small_factorial(n);
		int i=1000-1;
		while(fact[i]==0)
			i--;
		while(i>=0)
			cout << fact[i--];

		if(n2==100)
			cout << "00";
		cout << endl;
	}

	return 0;
}