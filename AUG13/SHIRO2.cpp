#include<iostream>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int ar[n+1];
    double p[n+1];
    ar[0] = 0;
    p[0] = 0;
    int v,i;
    int sum = 0;
    for(i=1;i<=n;i++){
      cin >> ar[i];
      sum += ar[i];
    }
    for(i=1;i<=n;i++){
      cin >> p[i];
      p[i] = p[i]/100.0;
    }
    double m[sum][n+1];
    int V = (sum-1)/2;
    for(v=0;v<=V;v++){
      for(i=0;i<=n;i++){
	m[v][i] = 0;
      }
    }
    m[0][0] = 1;
    double prod = 1;
    for(i=1;i<=n;i++){
      prod *= (1-p[i]);
      m[0][i] = prod;
    }
    for(v=1;v<=V;v++){
      for(i=1;i<=n;i++){
	m[v][i] = m[v][i-1]*(1-p[i]) + ( (v-ar[i]>=0)? (m[ v-ar[i] ][i-1]*p[i]):0 );
      }
    }
    double ans = 0;
    for(v=0;v<=V;v++){
      //      cout << v << ":\t";
      //      for(i=0;i<=n;i++){
      //	cout << m[v][i] << "\t";
      //      }
      //      cout << endl;
      ans += m[v][n];
    }
    ans = 1-ans;
    cout << ans << endl;
  }
  return 0;
}
