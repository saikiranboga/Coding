#include <stdio.h>
#include <string.h>

#define MAXN 10010

int parent[MAXN];
int rank[MAXN];
int score[MAXN];

void createSet(int x){
	parent[x] = x;
	rank[x] = score[x];
}

int findSet(int x){
	if(x!=parent[x])
		parent[x] = findSet(parent[x]);
	return parent[x];
}

void mergeSets(int x, int y){
	int px = findSet(x);
	int py = findSet(y);
	if(px==py)
		printf("Invalid query!\n");
	else if(rank[px]>rank[py])
		parent[py] = px;
	else if(rank[px]<rank[py])
		parent[px] = py;
}

int main()
{
	int t, i;
	scanf("%d",&t);
	while(t--){
		memset(parent,0,sizeof(parent));
		memset(rank,0,sizeof(rank));
		memset(score,0,sizeof(score));
		
		int n;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&score[i]);
			createSet(i);
		}

		int q, type, x, y;
		scanf("%d",&q);
		while(q--){
			scanf("%d %d",&type, &x);
			if(type == 0){
				scanf("%d",&y);
				mergeSets(x,y);
			} else{
				printf("%d\n",findSet(x));
			}
		}
	}
	return 0;
}


/*

2
1 2
2
0 1 2
1 1

4
1 2 3 4
19
1 1
1 2
1 3
1 4
0 1 4
1 1
1 2
1 3
1 4
0 2 3
1 1
1 2
1 3
1 4
0 3 4
1 1
1 2
1 3
1 4
*/