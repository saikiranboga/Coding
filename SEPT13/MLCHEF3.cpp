#include<cstdio>
#include<utility>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<limits.h>

using namespace std;

const int MAX = 100005;
int LEN;


//Stores adjacencny list representation of the graphs
vector<int> adj[MAX];

int arr[MAX] , health[MAX] , index[MAX][2] , seg[MAX], num [MAX], seg_ctr[1000];//denotes the start of the tree and 1 denotes the end
bool visited[MAX];
int ctr = 0;


int upperbound(int *a, int st, int en, int val){
  int idx, cnt, stp;
  cnt = en - st;
  while(cnt > 0){
    stp = cnt >> 1;
    idx = st + stp;
    if(a[idx] <= val)
      st = ++idx, cnt -= stp+1;
    else
      cnt = stp;
  }
  return st;
}

void DFS(int v){
  visited[v] = true;
  index[v][0] = ctr+1;
  arr[ctr++] = v;
  vector<int>::iterator i;
  for(i = adj[v].begin(); i != adj[v].end(); ++i)
    if(!visited[*i])
      DFS(*i);
  index[v][1] = ctr-1;
}

int main(){
  int N,Q,node,type,A,st,en,X;
  scanf("%d",&N);
  
  for(int i=1;i<=N;i++){
    scanf("%d%d",&health[i],&node);
    adj[node].push_back(i);
  }
  LEN = sqrt(N+1);

  //Do a DFS and get the paranthesised for for the graph
  for(int i = 0; i < MAX; i++){
    visited[i] = false;
    seg[i] = INT_MAX;
  }
  DFS(0);

  //Store health value for the pranthesisd form
  /*for(int i=0;i<=N;i++)
    printf("%d %d",index[i][0],index[i][1]);*/

  for(int i=0;i<=N;i++){
    num[i] = health[arr[i]];
    seg[i] = num[i];
  }

  
  //Square root decomposition into blocks
  for(int i = 0; i <= N; i++){
    int j = min(i + LEN, N+1);
    sort(seg + i, seg + j);
    i = j - 1;
  }

  /*for(int i = 0; i <= N; i++)
    printf("%d ",seg[i]);*/

  scanf("%d",&Q);

  while(Q--){
    scanf("%d",&type);
    
    if(type == 2){
      scanf("%d",&A);
      if(adj[A].size()==0){
	printf("0\n");
	continue;
      }
      int x = index[A][0];
      int y = index[A][1];
      st = x / LEN;
      en = y / LEN;
      int k=0;
      if(st == en){
	for(int i = x ; i <= y; i++)
	  k += (num[i] > seg_ctr[st]);
	printf("%d\n", k);
      }
      else{
	int j = min((st + 1)*LEN, N+1);
	for(int i = x; i < j; i++) //Counting outsid the segment
	  k += (num[i] > seg_ctr[st]);
	for(int i = en * LEN; i <= y; i++) //Counting outsid the segment
	  k += (num[i] > seg_ctr[en]);
	for(int i = st + 1; i <= en - 1; i++) //Counting directly from the segments
	  k +=  min((i+1) * LEN,N+1) - upperbound(seg,i * LEN,min((i+1) * LEN, N+1), seg_ctr[i]) ;
	printf("%d\n", k);
      }
    }
    else{
      scanf("%d%d",&A,&X);
      int x = index[A][0];
      int y = index[A][1];
      st = x / LEN;
      en = y / LEN;
      //printf("%d %d %d %d\n",x,y,st,en);
      if(st == en){
	for(int i = x; i <= y; i++){
	  num[i] -= X;
	  seg[i] = num[i];
	}
	sort(seg + x, seg + y);
      }
      else{
	int j = min((st + 1)*LEN, N+1);
	for(int i = x; i < j; i++){ //Counting outsid the segment
	  num[i] -= X;
	  seg[i] = num[i];
	}
	sort(seg + x , seg + j-1 );
	for(int i = en * LEN; i <= y; i++){ //Counting outsid the segment       
	  num[i] -= X;
	  seg[i] = num[i];
	}
	sort(seg + min(en*LEN,N+1) , seg + N+1);
	for(int i = st + 1; i <= en - 1; i++) //Counting directly from the segments
	  seg_ctr[i] += X;
      }
      /*for(int i = 0; i <= N; i++)
	printf("%d ",seg[i]);*/
    }
  }
}
