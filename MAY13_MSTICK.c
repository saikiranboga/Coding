#include<stdio.h>
#include<stdlib.h>

int main(){
  float times[100000],lig_times[100000];
  int Q,N,i,j,L,R;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%f",&times[i]);
  }
  scanf("%d",&Q);
  for(i=0;i<Q;i++){

    scanf("%d %d",&L,&R);

    int lig_min = 1000000000;
    for(j=L;j<=R;j++){
      if(times[j] < lig_min)
	lig_min = times[j];
    }

    for(j=0;j<N;j++){
      if( (j>=L) && (j<=R) ){
	lig_times[j] = lig_min + ((times[j]-lig_min)/2.0);
      }
      else{
	lig_times[j] = times[j] + lig_min;
      }
    }
    
    double ans = -1;
    for(j=0;j<N;j++){
      if(lig_times[j] > ans){
	ans = lig_times[j];
      }
    }

    printf("%.1lf\n",ans);
  }
  return 0;
}
