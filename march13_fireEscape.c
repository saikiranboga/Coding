#include<stdio.h>
#define MOD 1000000007

int N[100001];
int S[100001];
int parent(int arr[],int i)
{
 if(arr[i]==-1)
   return -1;
 if(arr[i]==i)
   return i;
return parent(arr,arr[i]);
}
int main()
{
  int t,n,e,a,b,edge,i,k,pa,pb,m;
 scanf("%d",&t);
 while(t--)
 {
  scanf("%d %d",&n,&e);
  for(i=0;i<=n;i++)
   N[i]=-1;
  for(i=0;i<=n;i++)
   S[i]= 1;
  edge=0;
  while(e--)
  {
   scanf("%d %d",&a,&b);
   if(a==b)continue;
   if(N[a]==-1 && N[b]==-1)
   {
    N[a]=a;
    N[b]=a;
    edge++;
   }
   else
   {
    pa=parent(N,a);
    pb=parent(N,b);
    if(N[a]!=-1 && N[b]!=-1 && pa==pb)
     continue;
    else if(N[a]!=-1 && N[b]!=-1 && pa!=pb)
    {
     N[pa]=pb;
     edge++;
    }
    else if(N[a]==-1 && N[b]!=-1)
    {
     edge++;
     N[a]=b;
    }
    else if(N[b]==-1 && N[a]!=-1)
    {
     edge++;
     N[b]=a;
    }
   }
  }
  /* int chk;
  for(m=1;m<=n;m++){
    chk = parent(N,m);
    if(chk == -1){
      continue;
    }
    else if(chk != m){
      S[chk]++;
    }
    }*/
  int mul = 1;
  for(m=1;m<=n;m++){
    mul = (mul*S[m])%MOD;
  }
  mul = mul%MOD;
  printf("%d %d\n",n-edge,mul);
 }
 return 0;
}
