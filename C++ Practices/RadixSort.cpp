#include <iostream>
#include <cstring>
using namespace std;

void countingSort(string A[], string B[], int d, int k){
  int j;
  int C[10];
  memset(C,0,sizeof(C));
  for(j=0;j<k;j++)
    C[ (int)(A[j][d]-'0') ]++;

  for(j=1;j<10;j++){
    C[j] = C[j] + C[j-1];
  }

  for(j=k-1; j>=0; j--){
    B[C[ (int)(A[j][d]-'0') ]-1] = A[j];
    C[ (int)(A[j][d]-'0') ]--;
  }
}


int main(){
  string A[7] = {"329","457","657","839","436","720","355"};
  string B[7];

  for(int d=2;d>=0;d--){
    countingSort(A,B,d,7);
    for(int i=0;i<7;i++)
      A[i] = B[i];
  }
  for(int i=0;i<7;i++)
    cout << A[i] << endl;
  return 0;
}
