#include <iostream>
#include <vector>

using namespace std;

#define pb(a) push_back(a)

typedef struct ops{
public:
  int a,b;

  ops(int a, int b){
    this->a = a;
    this->b = b;
  }

}ops;

int main(){
  int i,n,tmp;
  vector<int> ar;
  vector<ops> out;
  int freq[100010] = {0};
  cin >> n;
  for(i=0;i<n;i++){
    cin >> tmp;
    freq[tmp]++;
    ar.pb(tmp);
  }

  int j,k,op1,op2,num_elem,flag = 0,n_elem=0,max = 1;
  while(ar.size() != 0){
    for( i=0; i<ar.size(); i++ ){
      if(freq[ar[i]] > 1){
	for( k=1; k<ar.size(); k++ ){
	  flag = 0;
	  num_elem = 1;
	  for( j=i+k; j<ar.size(); j+=k ){
	    if( (!flag) && (ar[j] != ar[j-k]) ){
	      flag = 1;
	      break;
	    }
	  }
	  if( !flag ){
	    op1 = i+1;
	    op2 = k;
	    j -= k;
	    cout << "case:\n";
	    cout << i << " " << k << endl;
	    for(j; j>=i; j-=k){
	      cout << j << "|";
	      ar.erase(ar.begin()+j);
	    }
	    cout << "\n";
	    ops ops_tmp = ops(op1, op2);
	    out.pb(ops_tmp);	 
	  }
	}
      }
      else{
	ops ops_tmp = ops(i+1, ar.size());
	ar.erase(ar.begin()+i);
	out.pb(ops_tmp);
      }
    }
  }

  int tot = out.size();
  cout << tot << endl;
  for(i=0; i<tot; i++){
    cout << out[i].a << " " << out[i].b << endl;
  }
  return 0;
}

