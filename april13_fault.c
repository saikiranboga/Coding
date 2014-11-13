#include<stdio.h>
#include<stdlib.h>

#define MAX 200

struct Node{
  int v;
  struct Node *next;
  int count;
};

typedef struct Node Node;

Node *chunks[MAX];

void insert_after(Node *m,Node *n){
  Node *temp;
  temp=m->next;
  m->next=n;
  n->next=temp;
}

int main(){

  int N,S,C,chk;
  int i,j;
  Node *server_n;

  scanf("%d%d",&N,&S);

  for( i = 0; i < N; i++ ){
    chunks[i] = (Node *)malloc(sizeof(Node));
    chunks[i]->v = i;
    chunks[i]->next = NULL;
    chunks[i]->count = 0;
  }

  for(i=0;i<S;i++){
    scanf("%d",&C);
    for(j=0;j<C;j++){
      scanf("%d",&chk);

      server_n = (Node *)malloc(sizeof(Node));
      server_n->v = i;

      chunks[chk]->count += 1;
      insert_after(chunks[chk],server_n);
    }
  }

  int min = S+1;
  int min_index = -1;
  for(i = 0; i < N; i++){
    if(chunks[i]->count < min){
      min = chunks[i]->count;
      min_index = i;
    }
  }

  int flag = 1;
  for(i = 0; i < N; i++){
    if(chunks[i]->count != N){
      flag = 0;
    }
  }
  if(flag == 1){
    printf("0\n");
  }
  else{
    int k = chunks[min_index]->count;
    printf("%d\n",k);
    Node *temp;
    int counter = 0;
    for( temp = chunks[min_index]->next; temp; temp = temp->next ){
      printf("%d",temp->v);
      if(counter != k)
	printf(" ");
    }
    printf("\n");
  }
  /*  printf("%d\n",S);
  for(i=0;i<S;i++){
    printf("%d",i);
    if(i!=S-1)
      printf(" ");
  }
  printf("\n");*/
  return 0;
}
