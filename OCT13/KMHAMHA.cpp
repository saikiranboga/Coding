#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long int

void qsort(ll a[], ll idx[], ll start, ll end)
{

  ll i = start;
  ll j = end;
  ll pivot = a[(i+j)/2];
  while(i <= j){
    while(a[i] < pivot)
      i++;
    while(a[j] > pivot)
      j--;
    if(i <= j){
      ll temp = a[i];
      a[i] = a[j];
      a[j] = temp;

      temp = idx[i];
      idx[i] = idx[j];
      idx[j] = temp;

      i++;
      j--;
    }
  }

  if(start < j)
    qsort(a, idx, start, j);
  if(end > i)
    qsort(a, idx, i, end);

}

void quickSort(ll arr[], ll idx[], ll low, ll high){
  ll i = low;
  ll j = high;
  ll y = 0;
  ll z = arr[(low + high) / 2];
  do {
    while(arr[i] < z) i++;
    while(arr[j] > z) j--;
    if(i <= j) {
      y = arr[i];
      arr[i] = arr[j];
      arr[j] = y;

      y = idx[i];
      idx[i] = idx[j];
      idx[j] = y;
      
      i++;
      j--;
    }
  } while(i <= j);
  if(low < j)
    quickSort(arr, idx, low, j);
  if(i < high)
    quickSort(arr, idx, i, high);
}

int main(){
  ll i,j,t,n;
  cin >> t;
  while(t--){
    cin >> n;
    ll x[n],y[n],xi[n],yi[n],flag[n];
    for(i=0;i<n;i++){
      cin >> x[i] >> y[i];
      xi[i] = i;
      yi[i] = i;
      flag[i] = 1;
    }
    quickSort(x,xi,0,n-1);
    quickSort(y,yi,0,n-1);

    ll x_idx = 0, y_idx = 0;
    ll x_c, y_c, rem = n;
    ll ans = 0;
    while(rem > 0){
      x_c = 1;
      y_c = 1;
      ll temp,tempi;
      for(i=0;i<n;i++){
	while(i<n && !flag[xi[i]] ){
	  i++;
	}
	if(i == n)
	  break;
	temp = 1;
	tempi = i;
	i++;
	while(i < n && x[i] == x[i-1]){
	  if(flag[xi[i]]){
	    temp++;
	  }
	  i++;
	}
	i--;
	if(temp >= x_c){
	  x_c = temp;
	  x_idx = tempi;
	}
      }

      for(i=0;i<n;i++){
	while(i<n && !flag[yi[i]]){
	  i++;
	}
	if(i == n)
	  break;	
	temp = 1;
	tempi = i;
	i++;
	while(i<n && y[i] == y[i-1]){
	  if(flag[yi[i]]){
	    temp++;
	  }
	  i++;
	}
	i--;
	if(temp >= y_c){
	  y_c = temp;
	  y_idx = tempi;
	}
      }
      //      cout << "\nrem: " << rem << " x_idx: " << x_idx << " y_idx: " << y_idx << " x_c: " << x_c << " y_c: " << y_c << endl << endl;
      if(x_c >= y_c){
	ans++;
	rem -= x_c;
	i = 0;
	while(x_c > 0){
	  if(flag[xi[i+x_idx]]){
	    flag[xi[i+x_idx]] = 0;
	    x_c--;
	  }
	  i++;
	}
      }
      else{
	ans++;
	rem -= y_c;
	i = 0;
	while(y_c > 0){
	  if(flag[yi[i+y_idx]]){
	    flag[yi[i+y_idx]] = 0;
	    y_c--;
	  }
	  i++;
	}	
      }
    }
    int dist_x = 1,dist_y = 1;
    for(i=1;i<n;i++){
      while(x[i] == x[i-1])
	i++;
      if(i<n)
	dist_x++;
    }

    for(i=1;i<n;i++){
      while(y[i] == y[i-1])
	i++;
      if(i<n)
	dist_y++;
    }
    if(dist_x < ans)
      ans = dist_x;
    if(dist_y < ans)
      ans = dist_y;
    cout << ans << endl;
  }
  return 0;
}
