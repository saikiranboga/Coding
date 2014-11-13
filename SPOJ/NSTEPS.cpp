#include <iostream>
using namespace std;

int main(){
	int n,x,y;
	cin >> n;
	while(n--){
		cin >> x >> y;
		int line1 = (x==y)?1:0;
		int line2 = (x-2==y)?1:0;
		if(!line1 && !line2){
			cout << "No Number\n";
		} else{
			if(line1){
				if(x%2)
					cout << 2*x-1 << endl;
				else
					cout << 2*x << endl;
			} else{
				if(x%2==0 && y%2==0)
					cout << x+y << endl;
				else{
					cout << x+y-1 << endl;
				}
			}
		}
	}
	return 0;
}