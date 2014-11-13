#include <stdio.h>

long long int ans[10000000];

long long int min(long long int a,long long int b){
  return (a>b?b:a);
}

void quickSort(long long int arr[], long long int idx[], long long int low, long long int high){
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


int isSorted(long long int ar[],long long int size){
  long long int i;
  for(i=1;i<size;i++){
    if(ar[i] > ar[i+1])
      return 0;
  }
  return 1;
} 

int main(){
  long long int t,N,K,i,count;
  scanf("%lld",&t);
  while(t--){
    count = 0;
    scanf("%lld%lld",&N,&K);
    long long int ar[N+1],sorted_ar[N+1],index_sorted[N+1],index[N+1];
    ar[0] = 0;
    sorted_ar[0] = 0;
    index[0] = 0;
    index_sorted[0] = 0;
    for(i=1;i<=N;i++){
      scanf("%lld",&ar[i]);
      index[i] = i;
      index_sorted[i] = i;
      sorted_ar[i] = ar[i];
    }
    long long int j,flag = 0;
    while(!isSorted(ar,N) && !flag){
      for(i=1;i<N;i++){
	j = min(i+K,N+1);
	ans[count] = i;
	count++;
	quickSort(ar,index_sorted,i,j-1);
	if(isSorted(ar,N)){
	  flag = 1;
	  break;
	}
      }
    }
    /*
    quickSort(sorted_ar,index_sorted,0,N);

    for(i=1;i<=N;i++){
      printf("%d ",index[i]);
    }
    printf("\n");

    for(i=1;i<=N;i++){
      printf("%d ",index_sorted[i]);
    }
    printf("\n");

    int count = 0;
    for(i=1;i<=N;i++){
      if(index[i] != index_sorted[i]){
	for(j=index_sorted[i];j>=)
      }
    }
    /*
    for(i=1;i<=N;i++){
      printf("%d ",sorted_ar[i]);
    }
    printf("\n");
    for(i=1;i<=N;i++){
      printf("%d ",index[i]);
    }
    printf("\n");
    */
    if(N==1 || count==0)
      printf("0\n\n");
    else{
      printf("%lld\n",count);
      for(i=0;i<count;i++){
	printf("%lld",ans[i]);
	i==(count-1)?printf(""):printf(" ");
      }
      printf("\n");
    }
  }
  return 0;
}

/*

1
10 3
8 2 5 7 3 1 4 10 9 6

 */
