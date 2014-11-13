#include <iostream>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int s,c;
    cin >> s >> c;
    int nums[s][s+c];
    
    for(int i=0;i<s;i++)
      cin >> nums[0][i];
    
    for(int i=1;i<s;i++){
      for(int j=0;j<s-i;j++){
        nums[i][j] = nums[i-1][j+1]-nums[i-1][j];
      }
    }

    for(int i=1;i<s+c;i++)
      nums[s-1][i] = nums[s-1][i-1];

    for(int i=s-2;i>=0;i--){
      for(int j=s-i;j<s+c;j++){
        nums[i][j] = nums[i][j-1]+nums[i+1][j-1];
      }
    }

    for(int i=s;i<s+c;i++)
      cout << nums[0][i] << " ";
    cout << endl;

  }
  return 0;
}