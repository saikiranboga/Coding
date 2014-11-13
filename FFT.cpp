#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

#define PI acos(-1)
#define FOR(i,n) for(i=0;i<n;i++)
#define MAX 10100000

typedef long long int lli;
typedef complex<double> cd;
cd ta[MAX];

int pow(int a,int b){
  int temp;
  if(b == 0)
    return 1;
  if(b == 1)
    return a;
  temp = pow(a,b/2);
  if(b%2){
    return temp*temp*a;
  }
  else
    return temp*temp; 
}

int rev_bits_rec(unsigned int num, unsigned int numBits){
  unsigned int reversedNum;
  unsigned int mask = 0;
  
  mask = (0x1 << (numBits/2)) - 1;
  
  if (numBits == 1) return num;
  reversedNum = rev_bits_rec(num >> numBits/2, numBits/2) |
    rev_bits_rec((num & mask), numBits/2) << numBits/2;
  return reversedNum;
}

void BIT_REVERSE_COPY(cd a[], int N){
  int i;
  FOR(i,N){
    int c;
    c = a[i];
    ta[rev_bits_rec(c,4)>>1] = a[i];

  }
  FOR(i,N)
    a[i] = ta[i];
}

void ITERATIVE_FFT( cd a[], int N ){
  BIT_REVERSE_COPY(a,N);
  int i,lgn=0;
  for(i=2;i<=N;i*=2)
    lgn++;
  for(int s=1; s<=lgn; s++){
    int m = pow(2,s);
    cd w_m = cd( cos(2*PI/m), sin(2*PI/m) );
    int size = (N-1)/m;
    cd t;
    for(int k=0; k<=size; k++ ){
      cd w = 1;
      int t,u,bnd = m/2-1;
      for(int j=0; j<=bnd; j++){
	t = w*a[k+j+m/2];
	u = a[k+j];
	a[k+j] = u+t;
	a[k+j+m/2] = u-t;
	w = w*w_m;
      }
    }
  }

}


int main(){
  int i,N = 8;
  cd a[8] = {0,1,2,3,4,5,6,7};
  FOR(i,N)
    cout << a[i] << " ";
  cout << "\n";
  return 0;
}

