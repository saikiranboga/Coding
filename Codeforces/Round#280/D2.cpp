#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<cmath>
#include<utility>
#include<set>
using namespace std;
int main(){
	string op[3] = {"Vanya","Vova","Both"};
	long long arr[200010],x,y,n,a;
	memset(arr, -1, sizeof arr);
	cin >> n >> x >> y;
	//cout << n << ' ' << x << ' ' << y << endl;
	long long lx = 1, ly = 1,step = 1;
	while((lx <= x) && (ly <= y)){
		//cout << n << endl;
		if(ly*x > lx*y){
			arr[step++] = 0;
			lx++;
		}
		else if(ly*x < lx*y){
			arr[step++] = 1;
			ly++;
		}
		else{
			arr[step] = arr[step+1] = 2;
			step += 2;
			lx++; 
			ly++;
		}
	}
	//cout << "HERE " << n << endl;
	for(int i = 0; i < n; ++ i){
		cin >> a;
		a %= (x + y);
		if(a == 0){
			cout << op[arr[x+y]] << endl;
		}
		else
			cout << op[arr[a]] << endl;
	}
	return 0;
}