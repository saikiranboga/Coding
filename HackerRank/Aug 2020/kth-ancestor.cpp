#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std; 
#define MAX 100010
 
struct Node{
  int parent;
  int node;
  int exists;
  int leaf;
  int level;
};
 
typedef struct Node Node;
 
Node *vertex[MAX];
 
int main(){
  int t,i,j, nod, par, x, y, k, p, q, type;
  cin >> t;
  while(t--){
    cin >> p;
 
    for( i=0; i<=MAX; i++ ){
      vertex[i] = (Node *)malloc(sizeof(Node));
      vertex[i]->node = i;
      vertex[i]->exists = 0;
      vertex[i]->leaf = 1;
    }

    cin >> nod >> par;
    int root = nod;
    vertex[nod]->parent = par;
    vertex[nod]->exists = 1;
    vertex[par]->leaf = 0; 
    vertex[nod]->level = 0;

    for( i=2; i<=p; i++ ){
      cin >> nod >> par;
      vertex[nod]->parent = par;
      vertex[nod]->exists = 1;
      vertex[par]->leaf = 0;
      vertex[nod]->level = vertex[par]->level + 1;
    }
    cin >> q;
    for( i=1; i<=q; i++ ){
      cin >> type;
      if(type == 0){
	cin >> x >> y;
	vertex[x]->leaf = 0;
	vertex[y]->parent = x;
	vertex[y]->exists = 1;
	vertex[y]->leaf = 1;
	vertex[y]->level = vertex[x]->level + 1;
      }
      else if(type == 1){
	cin >> x;
	vertex[x]->exists = 0;
      }
      else{
	cin >> x >> k;
	if( vertex[x]->exists && k == vertex[x]->level)
	  cout << root << endl;
	else if(vertex[x]->exists && k < vertex[x]->level ){
	  par = vertex[x]->parent;
	  k--;
	  while(k>0 && par != 0){
	    par = vertex[par]->parent;
	    k--;
	  }
	  cout << par << endl;
	}
	else{
	  cout << "0\n";
	}
      }

    }
  }
  return 0;
}
