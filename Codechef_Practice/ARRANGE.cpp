#include <iostream>
#include <stdio.h>
using namespace std;

unsigned reverse_bits(unsigned input){  
  //works on 32-bit machine
  input = (input & 0x55555555) <<  1 | (input & 0xAAAAAAAA) >>  1;
  input = (input & 0x33333333) <<  2 | (input & 0xCCCCCCCC) >>  2;
  input = (input & 0x0F0F0F0F) <<  4 | (input & 0xF0F0F0F0) >>  4;
  input = (input & 0x00FF00FF) <<  8 | (input & 0xFF00FF00) >>  8;
  input = (input & 0x0000FFFF) << 16 | (input & 0xFFFF0000) >> 16;

  return input;
}

int main(){
  unsigned int t,i,k,n;
  cin >> t;
  while(t--){
    string s;
    cin >> k >> s; 
    n = s.length();
    char c[n+1];
    k = 32-k;
    for(i=0;i<n;i++){
      c[reverse_bits(i)>>k] = s[i];
    }
    c[n] = '\0';
    cout << c << endl;
  }
  return 0;
}
