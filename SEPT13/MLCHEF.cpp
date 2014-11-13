#include<stdio.h>
#include<stdlib.h>

#define MAX 100010
/*
inline void fastRead(int *a)
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
*/
int x;
struct Node{
  int v;
  struct Node *next;
  long long int h;
  int inf;
  int sup;
};

typedef struct Node Node;

Node *vertex[MAX];

int dfs(int a){
  int hlth,num_minus = 0;
  Node *temp;
  if(vertex[a]->inf > 0){
    for( temp = vertex[a]->next; temp; temp = temp->next ){
      hlth = temp->h;
      if(hlth > 0){
	temp->h -= x;
	hlth = temp->h;
	if(hlth <= 0){
	  num_minus++;
	}
      }
      if(temp->inf > 0)
	num_minus += dfs(temp->v);
    }
    vertex[a]->inf -= num_minus;
  }
  return num_minus;
}

void insert_after(Node *m,Node *n){
  Node *temp;
  m->inf += 1;
  temp = m->next;
  m->next = n;
  n->next = temp;
}

int main(){

  int n,sup,i;
  int health;
  Node *source_n,*dest_n;

  scanf("%d",&n);
  //fastRead(&n);

  for( i = 0; i <= n; i++ ){
    vertex[i] = (Node *)malloc(sizeof(Node));
    vertex[i]->v = i;
    vertex[i]->h = 0;
    vertex[i]->inf = 0;
    vertex[i]->sup = 0;
    vertex[i]->next = NULL;
  }

  for( i = 1; i <= n; i++){
    scanf("%d %d",&health,&sup);
    //    fastRead(&health);
    //    fastRead(&sup);
    
    dest_n=(Node *)malloc(sizeof(Node));
    dest_n->v = i;
    dest_n->h = health;

    vertex[i]->h = health;
    vertex[i]->sup = sup;

    insert_after(vertex[sup],dest_n);
  }

  for(i = n-1; i>0;i--){
    int super = vertex[i]->sup;
    while(super != 0){
      vertex[super]->inf += vertex[i]->inf;
      super = vertex[super]->sup;
    }
    vertex[0]->inf += vertex[i]->inf;
  }

  int q,type,a,tot_minus,super;
  scanf("%d",&q);
  //fastRead(&q);
  for(i=1; i<=q; i++){
    scanf("%d",&type);
    //fastRead(&type);
    if(type == 1){
      scanf("%d %d",&a,&x);
      //fastRead(&a);
      //fastRead(&x);
      tot_minus = dfs(a);
      super = vertex[a]->sup;
      while(super != 0){
	vertex[super]->inf -= tot_minus;
	super = vertex[super]->sup;
      }
      if(a != 0)
	vertex[0]->inf -= tot_minus;
    }
    else{
      scanf("%d",&a);
      //fastRead(&a);
      int ans = vertex[a]->inf;
      printf("%d\n",ans);
    }
  }
  return 0;
}
