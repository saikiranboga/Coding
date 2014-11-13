#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

#define PI 3.1415926
#define inf 1000000000

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)

#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) cout << n

/* Function to reverse arr[] from start to end*/
void reverseArray(int arr[], int start, int end)
{
  int temp;
  while(start < end)
  {
    temp = arr[start];   
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }   
}

bool is_sorted (int a[], int first, int last)
{
  fu(i,0,last-1){
  	if(a[i]>a[i+1])
  		return false;
  }
  return true;
}

int main(){
	int n;
	cin >> n;
	int nums[n];
	bool already_sorted = true;
	rep(i,n){
		cin >> nums[i];
	}
	int dif[n];
	rep(i,n-1){
		dif[i] = nums[i+1]-nums[i];
	}

	int start = -1, end = -1;
	bool seg = false;
	bool possible = true;
	
	rep(i,n-1){
		if(dif[i]<0){
			if(seg==true){
				possible = false;
				break;
			}
			seg = true;
			start = i;
			while(i<n-1 && dif[i]<=0) i++;
			end = i;
		}
	}

	reverseArray(nums,start,end);

	possible = is_sorted(nums,0,n-1);

	if(possible){
		if(seg==false){
			cout << "yes\n" << 1 << " " << 1 << endl;
		}
		else{
			cout << "yes\n" << start+1 << " " << end+1 << endl;
		}
	}
	else{
		cout << "no\n";
	}

	return 0;
}