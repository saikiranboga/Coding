#include <iostream>
 
using namespace std;
 
int ar[100010];
int freq[100010] = {0};
 
int main(){
  int i,n,op1,op2,j,num_elem,n_elem=0;
  cin >> n;
  cin >> ar[0];
  freq[ar[0]]++;
  int count = 0;
  for(i=1; i<n; i++){
    cin >> ar[i];
    freq[ar[i]]++;
    if(!count && ar[i] != ar[i-1])
      count = 1;
  }
  if(count == 0){
    cout << 1 << endl;
    cout << 1 << " " << 1 << endl;
  }
  else{
    int k,_n,max=1,flag;
    if(n>1000)
      _n = n/100;
    else if(n>500)
      _n = n/50;
    else if(n>200)
      _n = n/20;
    else if(n>100)
      _n = n/10;
    else
      _n = n;
      
    for( i=0; i<_n; i++ ){
      if(freq[ar[i]] > 1){
	for( k=1; k<n; k++ ){
	  flag = 0;
	  num_elem = 1;
	  for( j=i+k; j<n; j+=k ){
	    if( (!flag) && (ar[j] != ar[j-k]) ){
	      flag = 1;
	      break;
	    }
	    else{
	      num_elem++;
	    }
	  }
	  if( (!flag) && (num_elem > max) ){
	    max = num_elem;
	    op1 = i+1;
	    op2 = k;
	    n_elem = num_elem;
	  }
	}
      }
    }

    if( (n_elem > 1) && (!flag) ){
      int rem_elem = n-n_elem;
      cout << rem_elem+1 << endl;
      cout << op1 << " " << op2 << endl;
      for(i=rem_elem; i>0; i--){
	cout << i << " " << 1 << endl;
      }
    }
    else{
      cout << n << endl;
      for(i=n; i>0; i--){
	cout << i << " " << 1 << endl;
      }
    }

  }
  return 0;
} 
