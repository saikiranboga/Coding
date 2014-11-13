#include <iostream>
#include <string.h>
using namespace std;

int main(){
  long long int a,n,k,i;
  cin >> a >> n >> k;
  if(a == 0 || n==0){
    for(i=0; i<k; i++)
      cout << 0 << " ";
    cout << endl;
  }
  else{
    int bit_rep[101];
    memset(bit_rep,0,101*sizeof(int));
    int idx = 0;
    int repr = n+1;
    while(a){
      bit_rep[idx] = a%repr;
      a /= repr;
      idx++;
    }
    for(i=0; i<k; i++)
      cout << bit_rep[i] << " ";
    cout << endl;
  }
  return 0;
}
