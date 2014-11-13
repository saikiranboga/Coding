#include<stdio.h>
#include<queue>
#include<vector>
#include<limits>
#include<limits.h>
using namespace std ;
 
int col[100000] ;
std::vector<int> adj[100000] ;
int C[100000] ;
 
 
typedef long long ll ;
 
std::vector<int> minC ;
std::vector<int> size ;
 
int getMin(int a , int b){return a < b ? a : b ;}
 
int bfs(int s){
 
  col[s] = 1 ;
  std::queue<int> q ;
  q.push(s) ;
  int toq , i ;
	
  int sz = 1 ;
  int min = INT_MAX ;
 
  while(! q.empty() ){
	
    toq = q.front() ;
    q.pop() ;
 
    if( C[toq] >= 0 && min > C[toq] )
      min = C[toq] ;
 
    for(i=0; i<adj[toq].size(); i++){
		
      if(! col[adj[toq][i]]){
			
	sz++ ;
 
	col[adj[toq][i]] = 1 ;
	q.push(adj[toq][i]) ;
 
	if(C[adj[toq][i]] >= 0 && min > C[adj[toq][i]])
	  min = C[toq] ;
      }
    }
 
    col[toq] = 2 ;
  }
	
  minC.push_back(min) ;
  return min ;
}
 
inline int read(){
 
  int n = 0 ;
  char c = getchar() ;
 
  while( c<48 || c>57 ) c = getchar() ;
 
  while( c>=48 && c<=57 ){
	
    n = (n<<3) + (n<<1) + (c-48) ;
    c = getchar() ;
  }
  return n ;
}
 
int main(){
 
  int T , M , N , i , n1 , n2 , minComp , j ;
  ll ans = 0 ;
	
  scanf("%d %d",&N,&M) ;
	
  for(i=0;i<M;i++){
		
    scanf("%d %d",&n1,&n2) ;
		
    n1-- ;
    n2-- ;
 
    adj[n1].push_back(n2) ;
    adj[n2].push_back(n1) ;
			
  }
 
  for(i=0;i<N;i++)
    scanf("%d",C+i) ;
 
  for(i=0;i<N;i++){		
    if(! col[i]){		
      bfs(i) ;
    }
  }
	
  if(minC.size()==1){
    printf("0\n") ;
    return 0 ;
  }
  else{
	
    int gMin = INT_MAX ;
    for(i=0 ; i<minC.size() ; i++){
		
      if(minC[i] == INT_MAX){
			
	printf("-1\n") ;
	return 0 ;
      }
 
      if( gMin > minC[i] )
	gMin = minC[i] ;
 
      ans += minC[i] ;
    }
 
    ans += ( gMin * (minC.size() -2)) ;
    printf("%lld\n",ans) ;
 
  }
 
  return 0 ;
}
