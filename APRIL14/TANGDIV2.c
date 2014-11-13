#include <stdio.h>

#define fore(i, l, r) for(i = (l); i < (r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define ford(i, up, bot) for(i = (up); i > (bot); --i)
#define fordi(i, up, bot) ford(i, up, bot-1)


int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,k,p,i,j;
    int flag = 1;
    scanf("%d %d %d",&n,&k,&p);
    int lt[k],rt[k],aa[p],bb[p];
    int l,r,a,b;
    forn(i, k){
      scanf("%d %d",&lt[i],&rt[i]);
      if(rt[i]+1<=n)
        rt[i] += 1;
      else
        rt[i] = 1;
    }
    forn(i, p)
      scanf("%d %d",&aa[i],&bb[i]);

    flag = 1;

    forn(i, p){
      a = aa[i];
      int fnd = 0;
      forn(j, k){
        if(lt[j]==a || rt[j]==a){
          fnd = 1;
          break;
        }
      }
      if(fnd==0){
        flag = 0;
        break;
      }
    }
    if(flag==1){
      forn(i, p){
        b = bb[i];
        if(b+1<=n)
          b++;
        else
          b = 1;
        int fnd = 0;
        forn(j, k){
          if(lt[j]==b || rt[j]==b){
            fnd = 1;
            break;
          }
        }
        if(fnd==0){
          flag = 0;
          break;
        }
      }
    }

    if(flag==0){
      printf("No\n");
    }
    else{
     printf("Yes\n"); 
    }

  }
  return 0;
}
/*
2
10 3 2
1 4
5 5
6 10
1 5
6 10
10 3 1
2 5
10 1
6 9
1 10
*/