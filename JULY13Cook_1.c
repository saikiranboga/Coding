#include<stdio.h>
#include<math.h>

void quickSort(long long int arr[], long long int low, long long int high){
  long long int i = low;
  long long int j = high;
  long long int y = 0;
  long long int z = arr[(low + high) / 2];
  do {
    while(arr[i] < z) i++;
    while(arr[j] > z) j--;
    if(i <= j) {
      y = arr[i];
      arr[i] = arr[j];
      arr[j] = y;

      i++;
      j--;
    }
  } while(i <= j);
  if(low < j)
    quickSort(arr, low, j);
  if(i < high)
    quickSort(arr, i, high);
} 

int main(){
  long long int i,N,D,ar[100010],ans=0;
  scanf("%lld %lld",&N,&D);
  for(i=0; i<N; i++)
    scanf("%lld",&ar[i]);
  quickSort(ar, 0, N-1);
  for(i=0;i<N-1;){
    if( fabs(ar[i]-ar[i+1]) <= D){
      ans++;
      i += 2;
    }
    else{
      i++;
    }
  }
  printf("%lld\n",ans);
  return 0;
}
