#include<stdio.h>
#include<stdlib.h>

#define MAX 100002

int K;
struct Node{
  int v;
  struct Node *next;
  int links;
  int flag;
};

typedef struct Node Node;

Node *vertex[MAX];

int dfs(int n){
  Node *temp;
  for( temp = vertex[n]->next; temp; temp = temp->next ){
    if(vertex[temp->v]->links <= K){
      return 0;
    }     
  }
  return vertex[n]->links;
}

void insert_after(Node *m,Node *n){
  Node *temp;
  if(!m->flag){
    m->flag = 1;
  }
  m->links += 1;
  temp = m->next;
  m->next = n;
  n->next = temp;
}

int main(){

  int N,M,i,p,q;
  Node *source_n,*dest_n;

  scanf("%d%d%d",&N,&M,&K);

  for( i = 0; i <= 100000; i++ ){
    vertex[i] = (Node *)malloc(sizeof(Node));
    vertex[i]->v = i;
    vertex[i]->links = 1;
    vertex[i]->flag = 0;
    vertex[i]->next = NULL;
  }

  for( i = 0; i < M; i++){
    scanf("%d%d",&p,&q);
    source_n = (Node *)malloc(sizeof(Node));
    source_n->v = p;
    source_n->links = vertex[p]->links + 1;

    dest_n=(Node *)malloc(sizeof(Node));
    dest_n->v = q;
    dest_n->links = vertex[q]->links + 1;

    insert_after(vertex[p],dest_n);
    insert_after(vertex[q],source_n);
  }
  int max = 0;
  int count;
  for(i = 0; i <= 100000; i++){
    if(vertex[i]->flag){
      count = dfs(i);
      if(count > max){
	max = count;
      }
    }
  }
  printf("%d\n",max);
  return 0;
}
