#include<stdio.h>
#include<stdlib.h>

#define MAX 1000002
#define LARGE 10000000

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
  int cost;
};

typedef struct Node Node;

Node *vertex[MAX];
int min(int a,int b){
  return (a<=b?a:b);
}

int dfs(int n){
  int mini = LARGE;
  Node *temp;
  vertex[n]->visited = 1;
  int cost = vertex[n]->cost;
  if( cost >=0 )
    mini = cost;
  for( temp = vertex[n]->next; temp; temp = temp->next ){
    if(vertex[temp->v]->visited != 1){
      mini = min(mini,dfs(temp->v));
    }     
  }
  return mini;
}

void insert_after(Node *m,Node *n){
  Node *temp;
  temp = m->next;
  m->next = n;
  n->next = temp;
}

int main(){

  int v_n, m, source, dest, i;
  int res;
  Node *source_n,*dest_n;
  // scanf("%d%d",&v_n,&m);
  fastRead(&v_n);
  fastRead(&m);

  for( i = 0; i <= v_n; i++ ){
    vertex[i] = (Node *)malloc(sizeof(Node));
    vertex[i]->v = i;
    vertex[i]->next = NULL;
    vertex[i]->visited = 0;
  }

  for( i = 0; i < m; i++){
    //    scanf("%d %d",&source,&dest);
    fastRead(&source);
    fastRead(&dest);

    source_n = (Node *)malloc(sizeof(Node));
    source_n->v = source;
    source_n->visited = 0;

    dest_n=(Node *)malloc(sizeof(Node));
    dest_n->v = dest;
    dest_n->visited = 0;

    insert_after(vertex[source],dest_n);
    insert_after(vertex[dest],source_n);
  }

  int cost;
  int minimum;
  for(i=1; i<=v_n; i++){
    //    scanf("%d",&cost);
    fastRead(&cost);
    vertex[i]->cost = cost;
  }

  res = 0;
  int n_comps = 0;
  int whole_min = LARGE;
  for(i = 1; i <= v_n; i++){
    if(vertex[i]->visited == 0){
      n_comps++;
      minimum = dfs(i);
      if(minimum == LARGE){
	res = -1;

      }
      else{
	if(res != -1){
	  whole_min = min(whole_min,minimum);
	  res = res+minimum;
	}
      }
    }
  }
  if(v_n == 1 || n_comps == 1){
    printf("0\n");
  }
  else if(res == -1){
    printf("-1\n");
  }
  else{
    printf("%d\n", res + ((n_comps-2)*whole_min) );
  }
  return 0;
}


/*

Input 1
6 6
1 2
2 3
1 3
4 5
5 6
4 6
1
3
5
2
4
6

Output 1
3


Input 2
3 1
2 3
1
-1
-1

Output 2
-1

Input 3
8 7
1 2
2 3
1 3
4 5
5 6
4 6
7 8
1
3
5
2
4
6
0
0
Output 3
3

Input 4
8 7
1 2
2 3
1 3
4 5
5 6
4 6
7 8
1
3
5
2
4
6
-1 -1
Output 4
-1

Input 5

1 0
1

Output 5
0
 */
