#include<stdio.h>
#include<stdlib.h>
#define MAX 3002

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

struct Node{
  int v;
  struct Node *next;
  int visited;
};
 
typedef struct Node Node;

Node *graph[MAX];              // adjacent list for all vertex
int num,art_pts;                       // current dfn
int dfn[MAX];                  // each vertex's depth first search number
int low[MAX];                  // earliest ancestor through back edge

void articulation(int check, int parent,int art[]){
  int childCount = 0;
  Node *adj;
  dfn[check] = low[check] = num++;
  graph[check]->visited = 1;
  adj = graph[check]->next;
  while(adj){
    int w = adj->v;
    if (dfn[w] < 0) {                 // w is a child of check
      childCount++;
      articulation(w, check, art);
      low[check] = (low[check] < low[w]) ? low[check] : low[w];
      if (parent >=0 && low[w] >= dfn[check]) { 
	//printf("Articulation point %d dfn = %d low[%d] = %d\n",check,dfn[check],w,low[w]);
	if(!art[check]){
	  art[check] = 1;
	  art_pts++;
	}
      }
    } 
    else if (w != parent) {           // w is a grand parent of check(back edge)
      low[check] = (low[check] < dfn[w]) ? low[check] : dfn[w];
    }
    adj = adj->next;
  }
  if (parent < 0 && childCount > 1) { // root has more than one child
    //printf("Articulation point %d, root has %d children\n",check,childCount);
    if(!art[check]){
      art[check] = 1;
      art_pts++;
    }
  }
}


void insert_after(Node *m,Node *n){
  Node *temp;
  temp = m->next;
  m->next = n;
  n->next=temp;
}

int main(){
  int t,n,m,cost,i,j,source,dest;            
  Node *source_n,*dest_n;
  fastRead(&t);
  while(t--){
    int art[MAX]={0};
    fastRead(&n);
    fastRead(&m);
    fastRead(&cost);
    for( i = 0; i < n; i++ ){
      graph[i] = (Node *)malloc(sizeof(Node));
      graph[i]->v = i;
      graph[i]->next = NULL;
      graph[i]->visited = 0;
    }
    for (i=0; i<n; i++) {
      dfn[i] = low[i] = -1;
    }
    for( i=0; i<m; i++){
      fastRead(&source);
      fastRead(&dest);
    
      source_n = (Node *)malloc(sizeof(Node));
      source_n->v = source;
    
      dest_n=(Node *)malloc(sizeof(Node));
      dest_n->v = dest;
      insert_after(graph[source],dest_n);
      insert_after(graph[dest],source_n);
    }
    num = 0;
    art_pts = 0;
    articulation(0,-1,art);
    printf("%d\n",art_pts*cost);
  }
  return 0;
}  

