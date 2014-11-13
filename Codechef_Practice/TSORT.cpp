#include <iostream>
#include <stdio.h>
using namespace std;

void quickSort(int a[], int start, int end){
  int i = start;
  int j = end;
  int pivot_idx = (start+end)/2;
  int pivot = a[pivot_idx];
  int temp;
  do{
    while(a[i] < pivot) i++;
    while(a[j] > pivot) j--;
    if(i <= j){
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;

      i++;
      j--;
    }
  }while(i <= j);

  if(start < j)
    quickSort( a, start, j );
  if(end > i)
    quickSort( a, i, end );

}

int main(){
  int t,i;
  //  cin >> t;
  scanf("%d",&t);
  int a[t];
  for(i=0;i<t;i++)
    //    cin >> a[i];
    scanf("%d",&a[i]);
  quickSort(a,0,t-1);
  for(i=0;i<t;i++)
    //    cout << a[i] << endl;
    printf("%d\n",a[i]);
  return 0;
}
