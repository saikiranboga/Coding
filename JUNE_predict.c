#include<stdio.h>
int main(){
  int t,i,j;
  scanf("%d",&t);
  int m,m_,bound;
  double p,q,temp,temp2,ans,pq2,pq2m;
  while(t--){
    scanf("%lf",&p);
    q = 1-p;
    ans = 0;
    pq2 = 2*p*q;
    for(m=0;m<=10000;m++){
      bound = 10000-m;
      pq2m = pq2*m;
      temp = p*m;
      for(m_=0;m_<=bound;m_++){
	temp2 = temp+(q*m_)+(pq2m + pq2*m_);
	if(temp2 > ans){
	  ans = temp2;
	}
      }
    }
    printf("%.10lf\n",ans);
  }
  return 0;
}
