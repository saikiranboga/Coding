#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std; 
#define MAX 100002
 
struct Node{
  int v;
  struct Node *next;
  int visited;
};
 
typedef struct Node Node;
 
Node *vertex[MAX];
 
int dfs(int n){
  Node *temp;
  vertex[n]->visited = 1;
  int ret = 1;
  for( temp = vertex[n]->next; temp; temp = temp->next ){
    if(vertex[temp->v]->visited != 1){
      ret += dfs(temp->v);
    }
  }
  return ret;
}
 
void insert_after(Node *m,Node *n){
  Node *temp;
  temp=m->next;
  m->next=n;
  n->next=temp;
}
 
int main(){
  int t, v_n, m, cost, source, dest, index,  i,j;
  Node *source_n,*dest_n;
 
  cin >> v_n >> m;
 
  for( i = 0; i < v_n; i++ ){
    vertex[i] = (Node *)malloc(sizeof(Node));
    vertex[i]->v = i;
    vertex[i]->next = NULL;
    vertex[i]->visited = 0;
  }
 
  for( i = 0; i < m; i++){
    cin >> source >> dest;
 
    source_n = (Node *)malloc(sizeof(Node));
    source_n->v = source;
    source_n->visited = 0;
 
    dest_n=(Node *)malloc(sizeof(Node));
    dest_n->v = dest;
    dest_n->visited = 0;
 
    insert_after(vertex[source],dest_n);
    insert_after(vertex[dest],source_n);
  }
  int temp,n_comps=0;
  long long int ans = 0;
  int counts[v_n],counts_sum[v_n];
  for(i = 0; i < v_n; i++){
    if(vertex[i]->visited == 0){
      vertex[i]->visited = 1;
      counts[n_comps] = dfs(i);
      n_comps++;
    }
  }
  counts_sum[n_comps-1] = counts[n_comps-1];
  for(i=n_comps-2;i>=0; i--)
    counts_sum[i] = counts[i]+counts_sum[i+1];

  if(n_comps>1){
    for(i=0;i<n_comps-1; i++)
      ans += counts[i]*counts_sum[i+1];
    cout << ans << endl;
  }
  else
    cout << "0\n";
  return 0;
}
