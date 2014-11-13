#include<iostream>

using namespace std;

#define Mx 1001

long long int ans[Mx*Mx][5];

int main(){
  long long int i,j,k,N;
  cin >> N;
  long long int img[N+1][N+1];

  for(i=0;i<=N;i++){
    for(j=0;j<=N;j++){
      img[i][j] = 0;
    }
  }

  for(i=1;i<=N;i++){
    for(j=1;j<=N;j++){
      cin >> img[i][j];
    }
  }

  long long int idx = 0;
  for(i=1;i<=N;i++){
    for(j=1;j<=N;j++){
      if(img[i][j] != 0){
	ans[idx][0] = img[i][j];
	ans[idx][1] = i;
	ans[idx][2] = i;
	ans[idx][3] = j;
	ans[idx][4] = j;
	idx++;
      }
    }
  }

  cout << idx << endl;
  for(i=0;i<idx;i++){
    for(j=0;j<=3;j++){
      cout << ans[i][j] << ' ';
    }
    cout << ans[i][4] << endl;
  }

  return 0;
}
