#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		string a,b;
		cin >> a >> b;
		int asize = a.size(), bsize = b.size();
		int max_size = asize>bsize?asize:bsize;
		int first[max_size], second[max_size], res[max_size+1];

		memset(first, 0, sizeof(first));
		memset(second, 0, sizeof(second));
		memset(res, 0, sizeof(res));

		for(int i=0;i<asize;i++) first[i] = a[i]-'0';
		for(int i=0;i<bsize;i++) second[i]= b[i]-'0';

		int sum, carry = 0;
		for(int i=0;i<max_size;i++){
			sum = first[i]+second[i]+carry;
			res[i] = sum%10;
			carry = sum/10;
		}
		res[max_size] = carry;

		int id = 0;
		while(id<=max_size && res[id]==0)id++;
		if(id>max_size){
			cout << 0 << endl;
		}
		else{
			for(;id<max_size;id++)
				cout << res[id];
			if(res[max_size]!=0)
				cout << res[max_size];
			cout << endl;
		}
	}
	return 0;
}