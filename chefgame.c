#include<stdio.h>
#include<math.h>
#define MAX 7000
#define MOD 747474747

long long int distances_int[MAX]={0};
int visited[MAX]={0};

int main(){
  int i,j,k,n,d,t;
  scanf("%d",&t);
  while(t--){
    scanf("%d%d",&n,&d);
    int points[n][d];
    for(i=0;i<n;i++){
      for(j=0;j<d;j++){
	scanf("%d",&points[i][j]);
      }
    }
    long long int sum = 1;
    long long int temp;
    long long int dist;
    long long int max,max_index;
    i = 0;
    while(1){
      max = -1;
      visited[i] = 1;
      for(j=0;j<n;j++){
	if(!visited[j]){
	  dist = 0;
	  for(k=0;k<d;k++){
	    temp = points[i][k]-points[j][k];
	    temp *= temp;
	    dist += temp;
	  }
	  if(dist > distances_int[j]){
	    distances_int[j] = dist;
	  }
	  if(distances_int[j] > max){
	    max = distances_int[j];
	    max_index = j;
	  }
	}
      }
      i = max_index;
      if(max == -1){
	break;
      }
      if(max != 0){
	sum = (sum*(max%MOD))%MOD;
      }
    }

    /*    for(i=0;i<n;i++){
      printf("%lld,",distances_int[i]);
      }

      printf("\n");*/

    /*    long long int sum = 1;
    long long int tmp;
    for(i=0;i<n;i++){
      tmp = distances_int[i];
      if(tmp != 0){
	tmp = tmp%MOD;
	sum = (sum*tmp)%MOD;
      }
      }*/
    printf("%lld\n",sum%MOD);
    for(i=0;i<n;i++){
      distances_int[i] = 0;
      visited[i] = 0;
    }
  }
  return 0;
}
/*
3
3 2
0 0
-1 -1
1 -1
5 2
0 0
-1 -1
2 2
3 2
1 4
1 1
1
 */

