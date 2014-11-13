#include<stdio.h>
int main(){
  int t,a,b,n,i,j,k,l,flag;
  int array[1000];
  scanf("%d",&t);
  array[0]=1;
  
  while(t--){
    scanf("%d%d%d",&a,&b,&n);
    j=2;
    for(i=1;i<n;i++){
      do{
	flag=0;
	for(k=0;k<i;k++){
	  for(l=0;l<i;l++){
	    if(a*array[k]-b*array[l] == j)
	      flag = 1;
	  }
	}
	j++;
      }while(flag == 1);
      array[i] = j-1;
    }
    for(i=0;i<n;i++){
      printf("%d ",array[i]);
    }
    printf("\n");
  }
  return 0;
}
