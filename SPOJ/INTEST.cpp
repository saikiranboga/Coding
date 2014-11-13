#include <cstdio>

int main(){
	int n,k,t;
	scanf("%d %d",&n,&k);
	int count = 0;
	while(n--){
		scanf("%d",&t);
		if(t%k==0){
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}