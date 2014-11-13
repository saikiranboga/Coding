#include <iostream>

using namespace std;

int main(){
  int i,j;
  char ar[6][3];
  for(i=5;i>=0;i--)
    for(j=2;j>=0;j--){
      cin >> ar[i][j];
    }
  for(i=0;i<6;i++){
    for(j=0;j<3;j++)
      cout << ar[i][j];
    cout << endl;
  }

  return 0;
}
