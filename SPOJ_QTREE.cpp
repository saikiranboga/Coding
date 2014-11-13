#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define NIL LCT
#define MN 10001
#define MM 20001
#define INF 10000000
using namespace std;
 
queue<int> q;
int cases,n,pnt[MN],a,b,c;
char s[10];
 
struct EDGE{
  int pnt,index,cost;
  EDGE *pre;
  EDGE (){}
  EDGE(int _pnt,int _cost,EDGE *_pre,int _index):pnt(_pnt),cost(_cost),pre(_pre),index(_index){}
}Edge[MM],*EP=Edge,*edge[MM];
 
inline void addedge(int a,int b,int c,int index){
  edge[a]=new(++EP)EDGE(b,c,edge[a],index);
  edge[b]=new(++EP)EDGE(a,c,edge[b],index);
}
 
struct LinkCutTree{
  struct NODE{
    int val,maxv;
    bool root;
    NODE *left,*right,*father;
    NODE (){}
    NODE(int _val,NODE *_left,NODE *_right,NODE *_father):val(_val),left(_left),right(_right),father(_father){root=true;}
  }LCT[MN],*NP,*node[MN];
     
  void update(NODE *&t){
    t->maxv=max(t->val,max(t->left->maxv,t->right->maxv));
  }
     
  void init(){
    NP=NIL;
    NIL->val=NIL->maxv=-INF;
    NIL->left=NIL->right=NIL->father=NIL;
    NIL->root=false;
    memset(node,0,sizeof(node));
  }
     
  void build(){
    q.push(1);
    node[1]=new(++NP)NODE(-INF,NIL,NIL,NIL);
    while(!q.empty()){
      int i=q.front();q.pop();
      for(EDGE *j=edge[i];j;j=j->pre)
	if(node[j->pnt]!=node[i]->father){
	  node[j->pnt]=new(++NP)NODE(j->cost,NIL,NIL,node[i]);
	  pnt[j->index]=j->pnt;
	  q.push(j->pnt);
	}
    }
  }
     
  void zig(NODE *&t){
    NODE *f=t->father,*r=t->right;
    t->father=f->father;
    if(f->root){
      t->root=true;
      f->root=false;
    }else{
      if(f->father->left==f) f->father->left=t;
      else f->father->right=t;
    }
    t->right=f,f->father=t,f->left=r,r->father=f;
    update(f);
  }
     
  void zag(NODE *&t){
    NODE *f=t->father,*l=t->left;
    t->father=f->father;
    if(f->root){
      t->root=true;
      f->root=false;
    }else{
      if(f->father->left==f) f->father->left=t;
      else f->father->right=t;
    }
    t->left=f;f->father=t,f->right=l,l->father=f;
    update(f);
  }
     
  void splay(NODE *&t){
    while(!t->root){
      if(t->father->root){
	if(t->father->left==t) zig(t);
	else zag(t);
      }else{
	if(t->father->father->left==t->father){
	  if(t->father->left==t) zig(t->father),zig(t);
	  else zag(t),zig(t);
	}else{
	  if(t->father->left==t) zig(t),zag(t);
	  else zag(t->father),zag(t);
	}
      }
    }
    update(t);
  }
     
  void Expose(NODE *&t){
    NODE *p=t,*q=NIL;
    while(p!=NIL){
      splay(p);
      p->right->root=true;
      p->right=q;
      p->right->root=false;
      update(p);
      q=p;p=p->father;
    }
  }
     
  void modify(int i,int key){
    node[i]->val=key;
    update(node[i]);
    splay(node[i]);
  }
     
  void query(int a,int b){
    Expose(node[a]);
    NODE *q=NIL,*p=node[b];
    while(p!=NIL){
      splay(p);
      if(p->father==NIL) printf("%d\n",max(p->right->maxv,q->maxv));
      p->right->root=true;
      p->right=q;
      p->right->root=false;
      update(p);
      q=p;p=p->father;
    }
  }
}tree;
 
void init(){
  EP=Edge;
  memset(edge,0,sizeof(edge));
  memset(pnt,0,sizeof(pnt));
}
         
int main(){
  scanf("%d",&cases);
  while(cases--){
    init();
    tree.init();
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
      scanf("%d%d%d",&a,&b,&c);
      addedge(a,b,c,i);
    }
    tree.build();
    while(scanf("%s",s),s[0]!='D'){
      if(s[0]=='C'){
	scanf("%d%d",&a,&b);
	tree.modify(pnt[a],b);
      }else{
	scanf("%d%d",&a,&b);
	tree.query(a,b);
      }
    }
  }
  return 0;
}
