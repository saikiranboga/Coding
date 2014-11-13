#include <bits/stdc++.h>
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

int main(){
	
	int n, m;
	n = 6;
	int a[6];
	int freq[10];
	for(int i=0; i<10; i++)
		freq[i] = 0;
	for(int i=0; i<n; i++){
		cin >> a[i];
		freq[ a[i] ]++;
	}

	int elem = 0;
	for(int i=1; i<10; i++){
		if(freq[i]>=4)
			elem = i;
	}

	if(elem==0)
		cout << "Alien\n";
	else{
		int mark[6];
		for(int i=0;i<6;i++)
			mark[i] = 0;
		for(int i=0;i<6;i++){
			if(a[i]==elem)
				mark[i] = 1;
		}
		int head = -1, body = -1;
		for(int i=0;i<6;i++){
			if(mark[i] == 0){
				if(head==-1)
					head = a[i];
				else
					body = a[i];
			}
		}
		if(head<body){
			cout << "Bear\n";
		}
		else{
			cout << "Elephant\n";
		}
	}

	return 0;
}