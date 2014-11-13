#include <iostream>
#include <string.h>
using namespace std;

int main(){
  int t,n,m,comp,i;
  cin >> t;
  int chef[501];
  int ass[501];
  while(t--){
    cin >> n >> m;
    int tasks[n+1];
    memset(tasks, 0, (n+1)*sizeof(int));
    for(i=0; i<m;i++){
      cin >> comp;
      tasks[comp] = 1;
    }
    int turn = 0;
    int chef_idx = 0;
    int ass_idx = 0;

    for(i=1;i<=n;i++){      
      if(!tasks[i]){
	if(!turn){
	  chef[chef_idx++] = i;
	  turn ^= 1;
	}
	else{
	  ass[ass_idx++] = i;
	  turn ^= 1;
	}
      }
    }

    for(i=0; i<chef_idx; i++)
      cout << chef[i] << " ";
    cout << endl;
    for(i=0; i<ass_idx; i++)
      cout << ass[i] << " ";
    cout << endl;
  }
  return 0;
}
