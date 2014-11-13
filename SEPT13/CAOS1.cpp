#include <iostream>
#include <algorithm>
using namespace std;

#define max 51

int main() {
  int t1,n,m,i,j,count,l,r,t,b,z,min1,min2,min3;
  char a[max][max];
  cin >> t1;
  while(t1>0){
    count = 0;    
    cin >> n >> m;
    for(i=0;i<n;i++){
      for(j=0;j<m;j++)
	cin >> a[i][j];
    }
    for(i=2;i<n-1;i++){
      for(j=2;j<m-1;j++){	
	l=0;
	r=0;
	t=0;
	b=0;
	if(a[i][j] == '^'){		
	  for(z = j-1; z >= 0; z--){	    
	    if(a[i][z]=='^')
	      l++;
	    else
	      break;
	  }
	  for(z=i-1;z>=0;z--){
	    
	    if(a[z][j]=='^')
	      t++;
	    else
	      break;
	  }
	  for(z=j+1;z<m;z++){
	    if(a[i][z]=='^')
	      r++;
	    else
	      break;
	  }
	  for(z=i+1;z<n;z++){	   
	    if(a[z][j]=='^')
	      b++;
	    else
	      break;
	  }
	}
	min1 = min(l,r);
	min2 = min(t,b);
	min3 = min(min1,min2);	
	if(min3 >= 2)
	  count++;
      }
    }
    cout << count << endl;
    t1--;
  }
  return 0;
}
