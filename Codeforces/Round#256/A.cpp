#include <iostream>
using namespace std;

typedef long long int lli;
#define mp make_pair

int main(){
	int a[3],b[3];
	int aSum = 0, bSum = 0;
	for(int i=0;i<3;i++){
		cin >> a[i];
		aSum += a[i];
	}
	for(int i=0;i<3;i++){
		cin >> b[i];
		bSum += b[i];
	}
	int n;
	cin >> n;
	int nReq = 0;
	nReq += (aSum/5);
	nReq += (aSum%5==0)?0:1;
	nReq += (bSum/10);
	nReq += (bSum%10==0)?0:1;
	if(nReq<=n)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}