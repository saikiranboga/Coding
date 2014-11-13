#include <iostream>

using namespace std;

int main(){
  int rounds,t1,t2,s1=0,s2=0;
  cin >> rounds;
  int temp,winner,max = 0;
  while(rounds--){
    cin >> t1 >> t2;
    s1 += t1;
    s2 += t2;
    temp = s1-s2;
    if(temp > max){
      winner = 1;
      max = temp;
    }
    else{
      temp = s2-s1;
      if(temp > max){
	winner = 2;
	max = temp;
      }
    }
  }
  cout << winner << " " << max << endl; 
  return 0;
}
