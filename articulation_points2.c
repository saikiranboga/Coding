#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define min(a,b) ((a<b)?a:b)
     
     
int parent[3004],discovery[3004], back[3004],count=0,arti=0;
char art[3004];
     
typedef struct bfs
{
  int val;
  struct bfs *next;
} node;
     
node *ptr[3004]={NULL};
int visited[3004]={0};
     
void bft(int v)
{
  int i,j;
  bfs(0,v);
  memset(visited,0,3004*sizeof(int));
  memset(parent,0,3004*sizeof(int));
  memset(discovery,0,3004*sizeof(int));
  memset(back,0,3004*sizeof(int));
  memset(art,0,3004*sizeof(char));
}
void bfs(int v,int f)
{
  int u,i;
  node *tmp;
  u=v;
  visited[u]++;
  discovery[u]= ++count;
  back[u]= count;
  tmp=ptr[u];
  while(tmp)
    {
      if(visited[tmp->val]==0)
	{
	  //tmp->parent = u;
	  parent[tmp->val] = u;
	  //printf("%d",tmp->val);
	  bfs(tmp->val,f);
	  if(back[tmp->val] < discovery[u])
	    {
	      back[u] = min(back[u], back[tmp->val]);
	    }
	  else
	    {
	      if (art[u]==0)
		{ art[u]++; arti++;}
	    }
	}
      else
	{
	  if (parent[u] != tmp->val){
	    back[u] = min(discovery[tmp->val], back[u]);}
	}
      tmp=tmp->next;
    }
     
}
     
void input(int a, int b)
{
           
  create(a, b);
  create(b, a);
     
}
void printgraph(int v)
{
  int i;
  node *tmp;
  for(i=0;i<v;i++)
    {
      tmp=ptr[i];
      while(!(tmp==NULL))
	{
	  printf("%d: ",tmp->val);
	  tmp=tmp->next;
	}
      printf("\n");
    }
}
void fre(int v)
{
  int i;
  node *tmp, *prev;
  for(i=0;i<v;i++)
    {
      tmp=ptr[i];
                   
      while(tmp){
	prev = tmp;
	tmp=tmp->next;
	free(prev);
      }
      //free(ptr[i]);
    }
     
}
void create(int val,int i)
{
  node *nod,*tmp;
  nod = (node *)malloc(sizeof(node));
  nod->val=val;
  nod->next=NULL;
  tmp = ptr[i];
  if(!(tmp==NULL)){
      tmp = ptr[i]->next;
      ptr[i]->next = nod;
      nod->next = tmp;
  }
  else{
    ptr[i]=nod;
  }
}

int main()
{
  int t,v,m,k,i,cnt=0;
  node *tmp;
  scanf("%d",&t);
  while(t--){
    cnt=0;
    count=0;
    arti=0;
    scanf("%d %d %d",&v,&m,&k);
    for(i=0;i<m;i++){
      int a,b;
      scanf("%d %d",&a,&b);
      input(a,b);
    }
    bft(v);
    tmp=ptr[0];
    while(tmp)
      {
	cnt++;
	tmp=tmp->next;
      }
    if (cnt <= 1)
      arti--;
    printf("%d\n",arti*k);
    for(i=0;i<3004;i++)
      ptr[i]=NULL;
  }
  return 0;
}

/*
2
9 12 1
0 1
1 3
0 2
2 3
3 4
3 5
4 5
5 6
6 7
7 4
7 8
8 5
7 6 5
0 1
1 2
3 4
2 4
2 6
5 2
 */
