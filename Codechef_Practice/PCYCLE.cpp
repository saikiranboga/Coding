#include <iostream>
#include <string.h>
using namespace std;

int main(){
  int n,i,j,next;
  cin >> n;
  int a[n+1];
  int cycles[n+1][n+1];
  for(i=0;i<=n;i++)
    cycles[i][0] = 0;
  int visited[n+1];
  int idx = 1;
  memset(visited,0,(n+1)*sizeof(int));
  for(i=1;i<=n;i++)
    cin >> a[i];
  for(i=1;i<=n;i++){
    if(!visited[i]){
      visited[i] = 1;
      cycles[idx][1] = i;
      next = a[i];
      j = 2;
      while(next != i){
	visited[next] = 1;
	cycles[idx][j++] = next;
	next = a[next];
      }
      cycles[idx][j] = i;
      cycles[idx][0] = j;
      idx++;
    }
  }
  int elem;
  cout << idx-1 << endl;
  for(i=1;i<idx;i++){
    elem = cycles[i][0];
    for(j=1; j<=elem; j++){
      cout << cycles[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
