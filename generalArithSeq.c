#include<stdio.h>
//#include<string.h>
int used[2000000];

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int a,b,n;
    scanf("%d %d %d",&a,&b,&n);
    int x[1001] = {0};
    memset(used,0,sizeof(used));
    for(int i=1;i<=n;i++){
      x[i]=x[i-1]+1;
      while(used[x[i]])
	x[i]++;
      for(int k=1;k<=i;k++){
	int indx = a*x[k]-b*x[i];
	if(indx>0)
	  used[indx] = 1;
	
	indx = a*x[i]-b*x[k];
	if(indx>0)
	  used[indx] = 1;
      }
      printf("%d ",x[i]);
    }
    printf("\n");
  }
  return 0;
}
