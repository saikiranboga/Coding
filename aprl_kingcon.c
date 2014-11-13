#include<stdio.h>
#include<stdlib.h>
 
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
  for( temp = vertex[n]->next; temp; temp = temp->next ){
    if(vertex[temp->v]->visited != 1){
      dfs(temp->v);
    }
  }
}
 
void insert_after(Node *m,Node *n){
  Node *temp;
  temp=m->next;
  m->next=n;
  n->next=temp;
}
 
int main(){
  int t, v_n, m, cost, source, dest, index, count=0, i,j;
  long long int res;
  Node *source_n,*dest_n;
 
  scanf("%d",&t);
 
  while(t--){
 
    scanf("%d%d%d",&v_n,&m,&cost);
 
    for( i = 0; i < v_n; i++ ){
      vertex[i] = (Node *)malloc(sizeof(Node));
      vertex[i]->v = i;
      vertex[i]->next = NULL;
      vertex[i]->visited = 0;
    }
 
    for( i = 0; i < m; i++){
      scanf("%d%d",&source,&dest);
 
      source_n = (Node *)malloc(sizeof(Node));
      source_n->v = source;
      source_n->visited = 0;
 
      dest_n=(Node *)malloc(sizeof(Node));
      dest_n->v = dest;
      dest_n->visited = 0;
 
       insert_after(vertex[source],dest_n);
      insert_after(vertex[dest],source_n);
    }
    int disconnects = 0;
    for(i = 0; i < v_n; i++){
      vertex[i]->visited = 1;
      count = 0;
      for(j = 0; j < v_n; j++){
	if(vertex[j]->visited == 0){
	  count++;
	  dfs(j);
	}
      }
      for( j = 0; j < v_n; j++ ){
	vertex[j]->visited = 0;
      }
      if(count > 1){
	disconnects++;
      }
      vertex[i]->visited = 0;
    }
    printf("%d\n",cost*disconnects);
  }
  return 0;
}
