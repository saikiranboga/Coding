//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//using namespace std;

void poison(int a,int x,int[],int[],int[],int[]);
int count_inf(int i,int[],int[]);
void decr_sup(int i,int[],int[]);
int compare(const void *a,const void *b)
{
    return (*(int*)b-*(int*)a);
}

int sup[100002][2],n;
main()
{
    int q,i,k,type,A,X;
    //    cin>>n;
    scanf("%d",&n);
    sup[0][0]=-1;sup[0][1]=0;

    int pos[n+1],inf[n+1],upper[n+1],h[n+1];
    for(i=1;i<=n;i++)
    {
        pos[i]=-1;inf[i]=0;
	//        cin>>h[i]>>sup[i][0];
	scanf("%d %d",&h[i],&sup[i][0]);
        upper[i]=sup[i][0];
        sup[i][1]=i;
    }
    qsort(sup,n+1,2*sizeof(int),compare);
    //for(i=0;i<n+1;i++)cout<<sup[i][0]<<" "<<sup[i][1]<<endl;cout<<endl;

    i=0;
    while(sup[i][0]!=-1){
      k = sup[i][0];
      pos[sup[i][0]]=i;
      while(sup[i][0]==k)
	i++;
    }
    //for(i=0;i<n+1;i++)cout<<pos[i]<<endl;cout<<endl;
    for(i=1;i<=n;i++)inf[i]=count_inf(i,inf,pos);
    inf[0]=n;
    //for(i=0;i<=n;i++)cout<<inf[i]<<endl;cout<<endl;
    //    cin>>q;
    scanf("%d",&q);
    while(q--)
    {
      //      cin>>type;
      scanf("%d",&type);
    if(type==1)
    {
      //        cin>>A>>X;
      scanf("%d %d",&A,&X);
        poison(A,X,pos,inf,upper,h);
    }
    else
    {
      //        cin>>A;
      scanf("%d",&A);
      //        cout<<inf[A]<<endl;
      printf("%d\n",inf[A]);
    }}
}

void poison(int a,int x,int pos[],int inf[],int upper[],int h[])
{
    int i=pos[a];
    if(i!=-1)
    {
    while(sup[i][0]==a)
    {
        //int test=(h[sup[i][1]]>0);
        h[sup[i][1]]-=x;
        if(/*test==1 && */h[sup[i][1]]<=0){decr_sup(sup[i][1],inf,upper);h[sup[i][1]]=1000000000;}
        poison(sup[i][1],x,pos,inf,upper,h);
        i++;
    }
}}

int count_inf(int i,int inf[],int pos[])
{
    if(inf[i]>0)return inf[i];
    int j=pos[i];if(j==-1)return 0;
    while(sup[j][0]==i){inf[i]=inf[i]+1+count_inf(sup[j][1],inf,pos);j++;}
    return inf[i];
}

void decr_sup(int i,int inf[],int upper[])
{
    while(i!=0)
    {inf[upper[i]]--;i=upper[i];}
}
