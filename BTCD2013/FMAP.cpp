#include<stdio.h>
#include<stdlib.h>

#define MAX 100002
#define MOD 1000000007

struct Node{
  int v;
  struct Node *next;
  int par_set;
  int trav;
};

typedef struct Node Node;

Node *vertex[MAX];
int a[MAX];

void dfs(int n){
  Node *temp;
  vertex[n]->par_set = 1;
  vertex[n]->trav = 1;

  for( temp = vertex[n]->next; temp; temp = temp->next ){
    if(vertex[temp->v]->trav != 1 && vertex[temp->v]->par_set != 1){
      vertex[temp->v]->par_set = 1;
      a[temp->v] = n;
    }
  }
  for( temp = vertex[n]->next; temp; temp = temp->next ){
    if(vertex[temp->v]->trav != 1){
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

  int t, n, hq1, hq2, par, index, count=0, i;
  long long int res;
  Node *source_n,*dest_n;

  scanf("%d",&t);

  while(t--){
    scanf("%d %d %d",&n,&hq1,&hq2);
    for( i = 0; i <= n; i++ ){
      vertex[i] = (Node *)malloc(sizeof(Node));
      vertex[i]->v = i;
      vertex[i]->next = NULL;
      vertex[i]->par_set = 0;
      vertex[i]->trav = 0;
    }

    for( i = 1; i < hq1; i++){
      scanf("%d",&par);
      a[i] = par;
      source_n = (Node *)malloc(sizeof(Node));
      source_n->v = i;
      vertex[i]->par_set = 0;
      vertex[i]->trav = 0;

      dest_n=(Node *)malloc(sizeof(Node));
      dest_n->v = par;
      vertex[i]->par_set = 0;
      vertex[i]->trav = 0;

      insert_after(vertex[i],dest_n);
      insert_after(vertex[par],source_n);
    }

    a[hq1] = -1;

    for( i = hq1+1; i <= n; i++){      
      scanf("%d",&par);
      a[i] = par;
      source_n = (Node *)malloc(sizeof(Node));
      source_n->v = i;
      vertex[i]->par_set = 0;
      vertex[i]->trav = 0;

      dest_n=(Node *)malloc(sizeof(Node));
      dest_n->v = par;
      vertex[i]->par_set = 0;
      vertex[i]->trav = 0;

      insert_after(vertex[i],dest_n);
      insert_after(vertex[par],source_n);
    }
    a[hq2] = -1;
    dfs(hq2);

    for(i=1;i<hq2;i++)
      printf("%d ",a[i]);
    for(i=hq2+1;i<=n;i++)
      printf("%d ",a[i]);
    printf("\n");
  }
  return 0;
}
