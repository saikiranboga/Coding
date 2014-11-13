#include<stdio.h>

void quickSort(int arr[], int low, int high) {
  int i = low;
  int j = high;
  int y = 0;
  /* compare value */
  int z = arr[(low + high) / 2];
 
  /* partition */
  do {
    /* find member above ... */
    while(arr[i] < z) i++;
 
    /* find element below ... */
    while(arr[j] > z) j--;
 
    if(i <= j) {
      /* swap two elements */
      y = arr[i];
      arr[i] = arr[j];
      arr[j] = y;
      i++;
      j--;
    }
  } while(i <= j);
 
  /* recurse */
  if(low < j)
    quickSort(arr, low, j);
 
  if(i < high)
    quickSort(arr, i, high);
} 

int main(){
  int t,n,k,i;
  scanf("%d",&t);
  while(t--){
    scanf("%d%d",&n,&k);
    int array[n];
    int sum = 0;
    for(i=0;i<n;i++){
      scanf("%d",&array[i]);
      sum += array[i];
    }
    quickSort(array,0,n-1);
    k = k<(n-k)?k:n-k;
    int son_sum = 0;
    for(i=0;i<k;i++){
      son_sum += array[i];
    }
    printf("%d\n",(sum-2*son_sum));
  }
  return 0;
}
