/*CODE FROM GEEKSFORGEEKS */

#include <stdio.h>
#include <limits.h>
#include <iostream>
using namespace std;

long long int max(long long int a, long long int b) { return (a > b)? a : b; }

long long int max(long long int a, long long int b, long long int c) { return max(max(a, b), c); }

long long int maxCrossingSum(long long int arr[], long long int l, long long int m, long long int h)
{
  long long int sum = 0;
  long long int left_sum = INT_MIN;
  for (long long int i = m; i >= l; i--)
    {
      sum = sum + arr[i];
      if (sum > left_sum)
	left_sum = sum;
    }

  sum = 0;
  long long int right_sum = INT_MIN;
  for (long long int i = m+1; i <= h; i++)
    {
      sum = sum + arr[i];
      if (sum > right_sum)
	right_sum = sum;
    }

  return left_sum + right_sum;
}

long long int maxSubArraySum(long long int arr[], long long int l, long long int h)
{
  if (l == h)
    return arr[l];

  long long int m = (l + h)/2;

  return max(maxSubArraySum(arr, l, m),
	     maxSubArraySum(arr, m+1, h),
	     maxCrossingSum(arr, l, m, h));
}

int main(){
  long long int i,t,N,k,K;
  cin >> t;
  while(t--){
    cin >> N >> K;
    long long int a[N];
    long long int freq[N];
    cin >> a[0];
    freq[0] = a[0];
    for(i=1;i<N;i++){
      cin >> a[i];
      freq[i] += a[i-1];
    }
    long long int sm;
    long long int mn = freq[K]-freq[0];
    long long int m_idx = K;
    for(k=K+1;k<N-1;k++){
      sm = freq[k]-freq[k-K];
      if(sm < mn){
	mn = sm;
	m_idx = k;
      }
    }
    long long int max_sum1 = maxSubArraySum(a, 0, m_idx-K);
    long long int max_sum2 = maxSubArraySum(a, m_idx+1, N-1);
    cout << max_sum1 + max_sum2 << endl;
  }
  return 0;
}
