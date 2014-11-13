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

int main(){
  int t,N,C,Q,pos,dif,swap,i,L,R;
  scanf("%d",&t);
  while(t--){
    fastRead(&N);
    fastRead(&C);
    fastRead(&Q);
    pos = C;
    for(i=1;i<=Q;i++){
      fastRead(&L);
      fastRead(&R);
      if(L <= pos && R>=pos){
	dif = pos - L;
	swap = R-dif;
	pos = swap;
      }
    }
    printf("%d\n",pos);
  }
  return 0;
}
