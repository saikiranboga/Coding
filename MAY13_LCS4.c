#include<stdio.h>

inline void fastRead(int *a)
{
  register char c=0;
  while (c<33) c=getchar_unlocked();
  *a=0;
  while (c>33)
    {
      *a=*a*10+c-'0';
      c=getchar_unlocked();
    }
}


int preProcessMin[100000][20];
int preProcessMax[100000][20];

RMQMinMax(int N,int A[]){
  int i,j;
  for (i=0;i<N;i++){
    preProcessMin[i][0] = A[i];
    preProcessMax[i][0] = A[i];
  }
  for (j=1; (1<<j) <= N; j++)
    for (i=0; i+(1<<j)-1<N; i++){
      preProcessMin[i][j] = ( preProcessMin[i][j-1] <= preProcessMin[i+(1<<(j-1))][j-1] )? preProcessMin[i][j-1] : preProcessMin[i+(1<<(j-1))][j-1];
      preProcessMax[i][j] = ( preProcessMax[i][j-1] >= preProcessMax[i+(1<<(j-1))][j-1] )? preProcessMax[i][j-1] : preProcessMax[i+(1<<(j-1))][j-1];
    }
}
    
int queryMin(int A[],int start,int end){
  int diff = end-start;
  diff = 31 - __builtin_clz(diff+1);
  return ( preProcessMin[start][diff] <= preProcessMin[end-(1<<diff)+1][diff] )? preProcessMin[start][diff] : preProcessMin[end-(1<<diff)+1][diff];
}

int queryMax(int A[],int start,int end){
  int diff = end-start;
  if(diff < 0){
    return -1;
  }
  diff = 31 - __builtin_clz(diff+1);
  return ( preProcessMax[start][diff] >= preProcessMax[end-(1<<diff)+1][diff] )? preProcessMax[start][diff] : preProcessMax[end-(1<<diff)+1][diff];
}

int main(){
  int N,Q,L,R,i,times[100000];
  fastRead(&N); 
  for(i=0;i<N;i++){
    fastRead(&times[i]);    
  }
  RMQMinMax(N,times);
  fastRead(&Q); 
  for(i=0;i<Q;i++){
    fastRead(&L);
    fastRead(&R);
    int min = queryMin(times,L,R);
    int m1 = queryMax(times,L,R);
    int t1 = queryMax(times,0,L-1);
    int t2 = queryMax(times,R+1,N-1);
    int m2 = (t1>t2)?t1:t2;
    
    float ans = ((((float)(m1-min)/2)>m2)?(((float)(m1-min)/2)):m2)+min;

    printf("%.1f\n",ans);
  }
  return 0;
}
