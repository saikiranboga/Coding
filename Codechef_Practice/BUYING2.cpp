#include <iostream>
#include <algorithm>
using namespace std;

int compare(const void* a, const void* b){
  return ( *(int*)b - *(int*)a );
}

int main(){
  int t,n,i,cost;
  cin >> t;
  while(t--){
    cin >> n >> cost;
    int notes[n];
    int sum = 0;
    for(i=0;i<n;i++){
      cin >> notes[i];
      sum += notes[i];
    }
    int n_sweets = sum/cost;
    int t_cost = n_sweets*cost;
    qsort(notes,n,sizeof(int),compare);

    if(notes[0] >= t_cost)
      i = 1;
    else{
      for(i=1;i<n;i++){
	notes[i] += notes[i-1];
	if(notes[i] >= t_cost){
	  i++;
	  break;
	}
      }
    }
    if(i < n || n_sweets == 0)
      cout << -1 << endl;
    else
      cout << n_sweets << endl;    
  }
  return 0;
}
