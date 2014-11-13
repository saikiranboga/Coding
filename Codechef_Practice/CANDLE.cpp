#include <iostream>

using namespace std;

int main(){
  int t,i,c[10],temp,zeros;
  cin >> t;
  while(t--){
    int min_idx,min = 10;
    cin >> zeros;    
    for(i=1; i<10; i++){
      cin >> temp;
      if(temp < min ){
	min = temp;
	min_idx = i;
      }
    }

    if(min == 0)
      cout << min_idx << endl;
    else{
      if(zeros > 0 && zeros >= min){
	for(i=0;i<min;i++)
	  cout << min_idx;
	cout << min_idx << endl;
      }
      else{
	cout << 1 << 0;
	for(i=0;i<zeros;i++)
	  cout << 0;
	cout << endl;
      }
    }
  }
  return 0;
}
