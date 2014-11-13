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

long long int A[1000001]={0};
int n,m,c,u,v,k,p;

void update(int idx,int val){
  while(idx <= n){
    A[idx] += val;
    idx += (idx & -idx);
  }
}
long long int query(int idx){
  long long int sum=0;
  while(idx > 0){
    sum += A[idx];
    idx -= (idx & -idx);
  }
  return sum;
}
int main(){
  char chr;
  fastRead(&n);
  fastRead(&m);
  fastRead(&c);
  update(1,c);
  while(m--){
    chr = getchar();
    while(!(chr=='Q' || chr=='S'))
      chr = getchar();
    if(chr == 'Q'){
      fastRead(&p);
      printf("%lld\n",query(p));
    }else{
      fastRead(&u); fastRead(&v); fastRead(&k);
      update(u,k);
      update(v+1,-k);
    }
  }
  return 0;
}
