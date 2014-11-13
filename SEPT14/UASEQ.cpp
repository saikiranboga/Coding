#include <bits/stdc++.h>
using namespace std;

#define LL long long int

int main()
{
	LL n, k;
	cin >> n >> k;
	LL ar[n];
	for(int i=0;i<n;i++)
		cin >> ar[i];
	map<LL, LL> freq;
	map<LL, pair<LL,LL> > as;
	LL dif;
	for(int i=1; i<n; i++){
		dif = ar[i]-ar[i-1];
		if(freq.find(dif) != freq.end()){
			freq[ dif ]++;
			(as[ ar[i] - i*dif ].first)++;
			as[ ar[i] - i*dif ].second = dif;
		}
		else{
			freq[ dif ] = 1;
			as[ ar[i] - i*dif ].first = 1;
			as[ ar[i] - i*dif ].second = dif;
		}
	}

	if(n>3*k){
		int sz = freq.size();
		int maxd = 0, mxf = 0;
		map<LL, LL>::iterator it;
		for(it=freq.begin(); it != freq.end(); it++){
			if(it->second > mxf){
				mxf  = it->second;
				maxd = it->first;

			}
		}

		int fr = 0;
		vector< pair<LL,LL> > maxa;
		map< LL, pair<LL,LL> >::iterator it2;

		for(it2=as.begin(); it2 != as.end(); it2++ ){
			if(it2->second.first > fr){
				maxa.clear();
				fr = it2->second.first;
				maxa.push_back( make_pair(it2->first,(it2->second).second) );
			}
			else if( it2->second.first == fr )
				maxa.push_back( make_pair(it2->first,(it2->second).second) );
		}

		LL count = 0;
		LL a,d;
		for(int i=0; i<maxa.size(); i++){
			count = 0;
			a = maxa[i].first;
			d = maxa[i].second;
			for(int kk=0; kk<n; kk++){
				if(ar[kk] != a+kk*d)
					count++;
			}
			if(count <= k){
				break;
			}
		}

		for(int i=0; i<n; i++)
			cout << (a + i*d) << " ";
		cout << endl;
	}
	else{
		LL d, a, count;
		LL ans_d, ans_a = 1E10;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				d = ( ar[j] - ar[i] ) / (j-i);
				a = ar[i] - i*d;
				count = 0;
				for(int kk=0; kk<n; kk++){
					if(ar[kk] != a+kk*d)
						count++;
				}
				if(count <= k){
					if(ans_a==1E10){
						ans_a = a;
						ans_d = d;
					}
					else{
						if(a==ans_a){
							if(d<ans_d)
								ans_d = d;
						}
						else if(a < ans_a){
							ans_a = a;
							ans_d = d;
						}
					}
				}
			}
		}
		for(int i=0;i<n;i++)
			cout << (ans_a + i*ans_d) << " ";
		cout << endl;
	}
	return 0;
}