#include <stdio.h>

#define fore(i, l, r) for(i = (l); i < (r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define ford(i, up, bot) for(i = (up); i > (bot); --i)
#define fordi(i, up, bot) ford(i, up, bot-1)

int cut[50000001];

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,k,p,i,j;
    int flag = 1;
    scanf("%d %d %d",&n,&k,&p);
    int chef[k][2];
    int boy[p][2];
    int l,r,a,b;
    forn(i, k)
      scanf("%d %d",&chef[i][0], &chef[i][1]);
    forn(i, p)
      scanf("%d %d",&boy[i][0], &boy[i][1]);

    forn(i, k){
      l = chef[i][0];
      r = chef[i][1];
      cut[l] = 1;
      if(r+1<=n)
        cut[r+1] = 1;
      else
        cut[1] = 1;
    }
    flag = 1;
    forn(i, p){
      a = boy[i][0];
      b = boy[i][1];
      if( (cut[a]!=1) || (b+1<=n && cut[b+1]!=1) || (b+1>n && cut[1]!=1) ){
        flag = 0;
        break;
      }
    }
    if(flag==0){
      printf("No\n");
    }
    else{
     printf("Yes\n");
    }
    forn(i, k){
      l = chef[i][0];
      r = chef[i][1];
      cut[l] = 0;
      if(r+1<=n)
        cut[r+1] = 0;
      else
        cut[1] = 0;
    }
  }
	return 0;
}