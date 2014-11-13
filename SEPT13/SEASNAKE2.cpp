#include <iostream>
using namespace std;

int apples[1000000][2];
int plays[1000000];

int main(){
  int n,m,i,j,k,aps = 0;
  cin >> n >> m;
  int n_apples = n*m-1;
  for(i=0;i<n_apples;i++){
    cin >> apples[i][0] >> apples[i][1];
  }

  if(n == 1){
    cout << n_apples*m << endl;
    for(j=0;j<n_apples;j++){
      for(i=0;i<m;i++){
	cout << "3 ";
      }
    }
    cout << endl;
  }
  else if(m == 1){
    cout << n_apples*n << endl;
    for(j=0;j<n_apples;j++){
      for(i=0;i<n;i++){
	cout << "1 ";
      }
    }
    cout << endl;
  }
  else if(n%2 == 0){
    for(k=0;k<n_apples;k++){
      for(i=0;i<m-1;i++)
	plays[aps++] = 3;
      int rep = (n-2)/2;
      for(j=0;j<rep;j++){
	plays[aps++] = 1;
	for(i=0;i<m-2;i++)
	  plays[aps++] = 2;
	plays[aps++] = 1;
	for(i=0;i<m-2;i++)
	  plays[aps++] = 3;
      }
      plays[aps++] = 1;
      for(i=0;i<m-1;i++)
	plays[aps++] = 2;
      for(i=0;i<n-1;i++)
	plays[aps++] = 0;
    }
  }
  else{
    for(k=0;k<n_apples;k++){
      for(i=0;i<n-1;i++)
	plays[aps++] = 1;
      int rep = (m-2)/2;
      for(j=0;j<rep;j++){
	plays[aps++] = 3;
	for(i=0;i<n-2;i++)
	  plays[aps++] = 0;
	plays[aps++] = 3;
	for(i=0;i<n-2;i++)
	plays[aps++] = 1;
      }
	plays[aps++] = 3;
      for(i=0;i<n-1;i++)
	plays[aps++] = 0;
      for(i=0;i<m-1;i++)
	plays[aps++] = 2;
    }
  }
  if(n != 1 && m != 1){
    
    int x = 0,y = 0;
    int cur = 0;
    for(i=0;i<aps;i++){

      if(plays[i] == 0){
	x = (x-1+n)%n;
	if(apples[cur][0] == x && apples[cur][1] == y)
	  cur++;
      }
      else if(plays[i] == 1){
	x = (x+1)%n;
	if(apples[cur][0] == x && apples[cur][1] == y)
	  cur++;
      }
      else if(plays[i] == 2){
	y = (y-1+m)%m;
	if(apples[cur][0] == x && apples[cur][1] == y)
	  cur++;
      }
      else if(plays[i] == 3){
	y = (y+1)%m;
	if(apples[cur][0] == x && apples[cur][1] == y)
	  cur++;
      }
      if(cur == n_apples)
	break;
    }
    cout << i+1 << endl;
    for(j=0;j<=i;j++)
      cout << plays[j] << " ";
    cout << endl;
  }
  return 0;
}
