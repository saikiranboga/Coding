#include <iostream>
using namespace std;

int min(int a, int b){
  return a>b?b:a;
}

int mat[2001][2001];

int main(){
  int n,m,i,j,k,l,h;
  cin >> n >> m;
  string s;
  int all_1 = 1;
  for(i=0;i<n;i++){
    cin >> s;
    for(j=0;j<m;j++){
      mat[i][j] = int(s[j]-'0');
      if(mat[i][j] != 1)
	all_1 = 0;
    }
  }
  if(all_1){
    int tmp = min(n,m);
    if(n == m)
      cout << (tmp*(tmp+1)*(2*tmp+1))/6 << endl;
    else{
      long long int ans = 0;
      int othr = n+m-tmp;
      for(i=tmp;i>=1;i--){
	ans += (i*othr);
	othr--;
      }
      cout << ans << endl;
    }
  }
  else{
    int flag;
    long long int ans=0;
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
	h = 1;
	flag = 1;
	while(flag && ((i+h)<=n) && ((j+h)<=m) ){
	  flag = 1;
	  for(k=i;k<i+h;k++){
	    for(l=j;l<j+h;l++){
	      if(l>=k && mat[k][l] != 1){
		flag = 0;
		break;
	      }
	    }
	    if(flag == 0)
	      break;
	  }
	  if(flag){
	    ans++;
	    //	  cout << i << "," << j << ","<< h <<endl;
	  }
	  h++;
	}

      }
    }
    cout << ans << endl;
  }
  return 0;
}
