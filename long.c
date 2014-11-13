#include<stdio.h>
#include<stdlib.h>

#define MAX 100002

struct Node{
  int v;
  int wght;
  struct Node *next;
  int visited;
};

typedef struct Node Node;

Node *vertex[MAX];

int dfs(int startingVertex){
  Node *temp;
  int totalCost = 0;
  int cost;
  /*  if(vertex[startingVertex]->next == NULL && vertex[startingVertex]->visited != 1){
    vertex[startingVertex]->visited = 1;
    return vertex[startingVertex]->wght;
  }
  else{*/
  vertex[startingVertex]->visited = 1;
  for( temp = vertex[startingVertex]->next; temp; temp = temp->next ){
    if(vertex[temp->v]->visited != 1){
      printf("-%d-\n",temp->v);
      if(totalCost == 0){
	totalCost = vertex[temp->v]->wght;
      }
      cost = dfs(temp->v);
      if(cost > totalCost){
	//	totalCost = vertex[startingVertex]->wght;
	totalCost = cost;
      }
    }
  }
  return totalCost;
  //}
}

void insert_after(Node *m,Node *n){
  Node *temp;
  temp=m->next;
  m->next=n;
  n->next=temp;
}

int main(){

  int t, v_n, m, source, dest, weight,index, count=0, i;
  long long int res;
  Node *source_n,*dest_n;

  scanf("%d",&v_n);
  m = v_n;
  for( i = 0; i <= v_n; i++ ){
    vertex[i] = (Node *)malloc(sizeof(Node));
    vertex[i]->v = i;
    vertex[i]->wght = 0;
    vertex[i]->next = NULL;
    vertex[i]->visited = 0;
  }

  for( i = 1; i < m; i++){
    scanf("%d",&source); 
    scanf("%d",&dest);
    scanf("%d",&weight);

    source_n = (Node *)malloc(sizeof(Node));
    source_n->v = source;
    source_n->wght = weight;
    source_n->visited = 0;

    dest_n=(Node *)malloc(sizeof(Node));
    dest_n->v = dest;
    dest_n->wght = weight;
    dest_n->visited = 0;

    insert_after(vertex[source],dest_n);
    insert_after(vertex[dest],source_n);
  }
  printf("cost--%d\n",dfs(1));
  return 0;
}
