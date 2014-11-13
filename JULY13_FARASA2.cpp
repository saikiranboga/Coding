#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

#define max 100001
map<long long int,int> freq;

int n;
long long int ans = 0;

int temp[max];
int arr[max];

int sort(int left, int right){
  if (left < right){
    int m = left + (right - left) / 2;
    int a = sort(left, m);
    int b = sort(m + 1, right);
    if(freq.count(a+b));
    else{
      freq[a+b]++;
      printf("%d ",a+b);
      ans++;
    }
    return a+b;
  }
  else if(left == right){
    if(freq.count(arr[left]));
    else{
      freq[arr[left]]++;
      printf("%d ",arr[left]);
      ans++;
    }
    return arr[left];
  }
}

int main(){
  int temp;
  scanf("%d", &n);
  for(int i=0;i<n;i++)
    scanf("%d", &arr[i]);
  temp = sort(0,0) + sort(1,n-1);
  freq[temp]++;
  printf("%d ",temp);
  ans++;
  for(int i=1;i<n-1;i++){
    sort(0,i);
    sort(i+1,n-1);
  }
  printf("\n%d\n",ans);
  return 0;
}
