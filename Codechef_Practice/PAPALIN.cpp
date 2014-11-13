#include <iostream>
#include <stdio.h>
//#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace std;

vector<int> papal;

int palin(int n){
  int temp = n;
  int reverse = 0;
  while(temp){
    reverse = reverse*10 + (temp%10);
    temp = temp/10;
  }
  if(n == reverse)
    return 1;
  else    
    return 0;
}

int prime(int n){
  int i;
  for(i=floor(sqrt(n)); i>1; i--)
    if(n%i == 0)
      return 0;
  return 1;
}

int main(){
  int n;
  for(int i=2;i<=1003001;i++)
    if( palin(i) && prime(i) )
      papal.push_back(i);

  int size = papal.size();
  cout << size << endl;
  FILE* fp = fopen("papals.txt","w+");
  for(int i=0; i<size; i++)
    //    cout << papal[i] << ",";
    fprintf(fp,"%d,",papal[i]);

  /*
  cin >> n;
  if(n==1)
    cout << 2 << endl;  
  else{
    while( !palin(n) || !prime(n) ){
      n++;
    }
    cout << n << endl;
  }
  */
  return 0;
}
