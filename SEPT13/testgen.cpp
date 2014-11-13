#include <iostream>
#include <stdio.h>

using namespace std;

  int a[900001];

int main(){
  int i,j;
  int n = 899;
  FILE* fp = fopen("test.txt","w+");
  fprintf(fp,"30 30\n");
  for(i=0;i<n;i++){
    fprintf(fp,"1 1\n");
  }
  n = 399;
  fprintf(fp,"20 20\n");
  for(i=0;i<n;i++){
    fprintf(fp,"1 1\n");
  }
  return 0;
}
