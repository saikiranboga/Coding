#include<stdio.h>
#define MOD 1000000007

inline void fastRead(long long int *a)
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


long long int modpow(long long int base,long long int power){
    if (base == 0){
		return 0;
	}
	long long int result = 1;
	long long int base_mod = base%MOD;
    while( power > 0){
		if(power%2){
			result = (result*base_mod)%MOD;
		}
		base_mod = (base_mod*base_mod)%MOD;
		power = power/2;
    }
    return result;
}
 

int main(){
  setvbuf(stdin, NULL, _IOFBF, 32768);
  setvbuf(stdout, NULL, _IOFBF, 32768); 
  long long int t,i,j,k;
  long long int V,N;
  //scanf("%lld",&t);
  fastRead(&t);
  while(t--){
    long long int P[100];
    long long int Q[100];
    long long int L[100];

    long long int V,N,p0,p1,A0,B0,C0,M0,q0,q1,A1,B1,C1,M1;

    //scanf("%lld %lld",&V,&N);
    //scanf("%lld %lld %lld %lld %lld %lld",&p0,&p1,&A0,&B0,&C0,&M0);
    //scanf("%lld %lld %lld %lld %lld %lld",&q0,&q1,&A1,&B1,&C1,&M1);
    fastRead(&V);
    fastRead(&N);

    fastRead(&p0);
    fastRead(&p1);
    fastRead(&A0);
    fastRead(&B0);
    fastRead(&C0);
    fastRead(&M0);

    fastRead(&q0);
    fastRead(&q1);
    fastRead(&A1);
    fastRead(&B1);
    fastRead(&C1);
    fastRead(&M1);

    P[0] = p0;
    P[1] = p1;
    Q[0] = q0;
    Q[1] = q1;
	
	L[0] = P[0]*M1+Q[0];
    L[1] = P[1]*M1+Q[1];  
	
	long long int ans;
	int flag = 0;
    ans = 1;
	if(L[0] == 0 || L[1] == 0){
		flag = 1;
	}
	ans *= (L[0])%(MOD-1);
	ans *= (L[1])%(MOD-1);
	ans %= (MOD-1);
	
	A0 = (A0*A0)%M0;
	A1 = (A1*A1)%M1;
	
    for(j=2;j<N;j++){
      P[j] = ( (A0*P[j-1])%M0 + (B0*P[j-2])%M0 + C0 )%M0;
      Q[j] = ( (A1*Q[j-1])%M1 + (B1*Q[j-2])%M1 + C1 )%M1;
	  L[j] = P[j]*(M1)+Q[j];
	  if(L[j] == 0){
		flag = 1;
	  }
	  ans *= (L[j]%(MOD-1));
	  ans %= (MOD-1);
    }
	long long int act_ans;
    if(flag == 1){
		printf("1\n");
	}
	else{
		act_ans = modpow(V%MOD, ans);
		printf("%lld\n",act_ans);
	}
  }
  return 0;
}
