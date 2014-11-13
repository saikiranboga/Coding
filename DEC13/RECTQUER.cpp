#include <iostream>
using namespace std;

typedef struct Node{

  int val;
  int nums[11];
  int dist;
}Node;

int main(){
  int N;
  cin >> N;
  Node a[N][N];

  int i,j,m;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){

      for(m=1;m<=10;m++){
	a[i][j].nums[m] = 0;
      }

      cin >> a[i][j].val;
      a[i][j].nums[a[i][j].val] = 1;
    }
  }
  int v,n;
  i = 0;
  for(j=1;j<N;j++){
    v = a[i][j].val;
    for(m=1;m<=10;m++){
      if(a[i][j-1].nums[m] > 0)
	a[i][j].nums[m] += a[i][j-1].nums[m];
    }
  }

  j = 0;
  for(i=1;i<N;i++){
    v = a[i][j].val;
    for(m=1;m<=10;m++){
      if(a[i-1][j].nums[m] > 0)
	a[i][j].nums[m] += a[i-1][j].nums[m];
    }
  }

  for(i=1;i<N;i++){
    for(j=1;j<N;j++){
      for(m=1;m<=10;m++){
	if(a[i-1][j].nums[m]){
	  a[i][j].nums[m] += a[i-1][j].nums[m];
	}
	if(a[i][j-1].nums[m]){
	  a[i][j].nums[m] += a[i][j-1].nums[m];
	}
	if(a[i-1][j-1].nums[m]){
	  a[i][j].nums[m] -= a[i-1][j-1].nums[m];
	}

      }
      /*
      int dis = 0;
      for(m=1;m<=10;m++){
	if(a[i][j].nums[m] == 1)
	  dis++;
      }

      a[i][j].dist = dis;
      */
    }
  }
  /*
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      
      cout << '[';
      for(m=1;m<=10;m++){
	cout << a[i][j].nums[m] << ',';
      }
      cout << "]\t";
      
      //cout << a[i][j].dist << '\t';
    }
    cout << endl;
  }
  */
  int Q,q,x1,x2,y1,y2,x11,y11;
  cin >> Q;
  for(q=0;q<Q;q++){
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    int temp[11] = {0};
    for(m=1;m<=10;m++){
      temp[m] = a[x2][y2].nums[m];
    }

    y11 = y1-1;
    if(y11 >= 0){
      for(m=1;m<=10;m++){
	temp[m] -= a[x2][y11].nums[m];
      }
    }
    x11 = x1-1;
    if(x11 >= 0){
      for(m=1;m<=10;m++){
	temp[m] -= a[x11][y2].nums[m];
      }
    }

    if(x11>=0 && y11>=0){
      for(m=1;m<=10;m++){
	temp[m] += a[x11][y11].nums[m];
      }
    }
    /*
    cout << '[';
    for(m=1;m<=10;m++){
      cout << temp[m] << ',';
    }
    cout << ']' << endl;
    */
    int ans = 0;
    for(m=1;m<=10;m++){
      if(temp[m] > 0)
	ans++;
    }
    cout << ans << endl;
  }

  return 0;
}
