#include <stdio.h>
#include <limits.h>

int main(){
  int t,n;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    int a[n];
    int i;
    int min_sum = 0;
    scanf("%d",&a[0]);
    min_sum = a[0];
    int num_neg = 0;
    if(a[0] < 0)
      num_neg++;
    for(i=1;i<n;i++){
      scanf("%d",&a[i]);
      if(a[i] < 0)
	num_neg++;
      if(a[i] < 0)
	min_sum += a[i];
      else
	min_sum -= a[i];
    }
    int temp = a[0];
    num_neg--;
    for(i=1;i<n;i++){
      if(a[i] < 0)
	num_neg--;
      if(temp > 0 && a[i] < 0){
	temp = temp*a[i];
      }
      else if(temp < 0 && a[i] < 0 && !num_neg){
	temp += a[i];
      }
      else if(temp < 0 && a[i] < 0 && num_neg){
	temp *= a[i];
      }
      else if(temp < 0 && a[i] > 0){
	temp *= a[i];
      }
      else if(temp > 0 && a[i] > 0 && !num_neg){
	temp -= a[i];
      }
      else if(temp > 0 && a[i] > 0 && num_neg){
	temp *= a[i];
      }
      else{
	temp *= a[i];
      }
    }
    if(temp < min_sum){
      min_sum = temp;
    }
    printf("%d\n",min_sum);
  }
  return 0;
}
