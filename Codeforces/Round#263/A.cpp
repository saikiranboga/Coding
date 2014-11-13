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
	cin >> n;
	char A[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> A[i][j];
	int ct;
	bool posb = true;
	for(int i=0;posb && i<n;i++){
		for(int j=0;posb && j<n;j++){
			ct = 0;
			if(i-1>=0)
				if(A[i-1][j]=='o')
					ct++;
			if(i+1<n)
				if(A[i+1][j]=='o')
					ct++;
			if(j-1>=0)
				if(A[i][j-1]=='o')
					ct++;
			if(j+1<n)
				if(A[i][j+1]=='o')
					ct++;
			if(ct%2 != 0){
				posb = false;
				break;
			}
		}
	}
	if(posb)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}