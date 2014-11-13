#include<stdio.h>
#include<stdlib.h>
#define MAX 100004

struct Node{
  int a;
  int b;
};

typedef struct Node Node;

Node *climbs[10000000];

int main(){
  int t,i,i2,j,k,l,m,N,K,count,heights[MAX];
  scanf("%d",&t);
  while(t--){
    count = 0;
    for(i=0;i<10000000;i++){
      climbs[i] = (Node*)malloc(sizeof(Node));
    }

    scanf("%d",&N);
    for(i=0;i<N;i++){
      scanf("%d",&heights[i]);
    }

    for(i=0; i<=N-2; i++)
      for(j=i+1; j<=N-1; j++){
	int flag = 0;
	for(i2=0; i2<count; i2++ ){

	  k = climbs[i2]->a;
	  l = climbs[i2]->b;	
	  if(j-i == l-k){
	    K = j - i;
	    int flag2 = 0;
	    for(m=1; m<=K; m++){
	      if(heights[i+m]-heights[i+m-1] != heights[k+m]-heights[k+m-1]){
		flag2 = 1;
		break;
	      }
	    }
	    if(flag2 == 1){
	      flag = 1;
	    }
	    else{
	      flag = 0;
	    }
	  }
	  else{
	    flag = 1;
	  }
	  if(flag == 0){
	    break;
	  }
	}
	if(i2 == count){
	  climbs[count]->a = i;
	  climbs[count]->b = j;
	  count++;
	}
      }
    printf("%d\n",count);
  }
  return 0;
}
