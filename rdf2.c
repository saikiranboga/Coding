#include<stdio.h>
#include<stdlib.h>
float ar[1001][31];

//f(n,k) = 1/n( sigma [x = 0 to n-1] f(x,k-1))

//f(n,k) = 1/n( (n-1)*f(n-1,k) + f(n-1,k-1))

float f(int n,int k){
  float sum = 0;
  int i;
  /*  if(ar[n][k]){
    return ar[n][k];
    }*/
  if(k == 0){
    ar[n][k] = n;
    return n;
  }
  else if(n == 0){
    ar[n][k] = 0;
    return 0;
  }
  else{
    //    for(i=0;i<n;i++){ 
      ar[n-1][k] = f(n-1,k);
      ar[n-1][k-1] = f(n-1,k-1);
      sum += ((n-1)*(ar[n-1][k]) + (ar[n-1][k-1]));
      //    }
    ar[n][k]= (float)sum/n;    
    return ar[n][k];
  }
}

int main(){
  int n,k;
  n = 4; k = 2;
  int i,j,m,p,q,t;
  FILE* fp;
  fp = fopen("rdf2_out.txt","w");
  // scanf("%d",&t);
  /*  for(i=0;i<=n;i++){
    for(j=0;j<=k;j++){
      if(i<=j)
	ar[i][j] = 0;
      else
	ar[i][j] = -1;
    }
    }*/

  /*  for(i=0;i<=n;i++){
    ar[i][0] = i;
    }*/
  //  for(i=0;i<=1000;i++){
  //    for(j=0;j<=30;j++){
  ar[n][k] =  f(n,k);
      //    }
      //  }
  //  ar[n][k] =  f(n,k);
  //  while(t--){
  for(i=0;i<=n;i++){
    for(j=0;j<=k;j++){
      fprintf(fp,"(%d,%d):%f\t",i,j,ar[i][j]);
    }
    fprintf(fp,"\n");
  }
  //  scanf("%d",&p);
  //    scanf("%d",&q);
  //    printf("%f\n",ar[p][q]);
  //  }
  return 0;
}
