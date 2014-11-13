#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while( (cin>>n) && (n) ){
		stack<int> left, right;
		int a[n];
		for(int i=n-1;i>=0;i--)
			cin >> a[i];
		for(int i=0;i<n;i++)
			left.push(a[i]);
		int cur = 0;
		int top;
		while( left.size() ){
			top = left.top();
			if(top-cur!=1){
				while( right.size() && right.top()-cur==1 ){
					cur = right.top();
					right.pop();
				}
				right.push( left.top() );
				left.pop();
			} else{
				cur = left.top();
				left.pop();
			}
		}
		while( right.size() && right.top()-cur==1 ){
			cur = right.top();
			right.pop();
		}
		if( left.size()==0 && right.size()==0 ){
			cout << "yes\n";
		}
		else{
			cout << "no\n";
		}
	}
	return 0;
}