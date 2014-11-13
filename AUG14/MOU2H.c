#include <stdio.h>
#include <string.h>

#define LL long long int

#define M 1000000009
#define N 1048576
#define MX_H 10000000
#define OFFSET 4000010

static char _rbuf[8192*8];
static char *_rend = 0;
static char *_rpos = 0;
static int _getchar() {
    int n = read(0,_rbuf,sizeof _rbuf);
    if (n <= 0) {
        printf("EOF(%d)\n",n); exit(1);
    }
    _rend = _rbuf + n;
    _rpos = _rbuf+1;
    return *_rbuf;
}
 
#define mygetchar() ((_rpos<_rend)?*_rpos++:_getchar())
 
// inline int get_i() __attribute__((always_inline));
static int get_i() {
    int c;
    while (((c = mygetchar())) < '0') {}
    int n = c-'0';
    while (((c = mygetchar())) >= '0') {
        // if (c>'9') return n;
        n = n*10 + c - '0';
    }
    return n;
}
 
static void put_i(int n) {
#define BSIZE 16
    char buf[BSIZE];
    int bn = BSIZE-1;
    while (1) {
        buf[bn--] = '0'+(n%10);
        n = n / 10;
        if (n == 0) break;
    }
    while (bn<BSIZE-1) putchar(buf[++bn]);
    putchar('\n');
}
 
static int dump(int a[], int n) {
    int i=0;
    printf("line-dump:");
    while (i<n) printf("%d ",a[i++]);
    printf("\n");
}
 

LL s[N];
LL dp[N], last[MX_H];

int main(){
    LL i, t;
    int tmp;
    
    //scanf("%lld",&t);
    tmp = get_i();
    t = tmp;

    dp[0] = 1;
    while(t--){
        memset(last, 0, sizeof(last) );
        LL n;
        
        //scanf("%lld",&n);
        tmp = get_i();
        n = tmp;

        LL A[n];
        for(i=0;i<n;i++){
            //scanf("%d",&A[i]);
            tmp = get_i();
            A[i] = tmp;
        }

        for(i=0;i<n-1;i++)
            s[i+1] = A[i+1]-A[i]+OFFSET;

        for(i=1; i<n; i++){
            dp[i] = dp[i-1] << 1;
            if(last[s[i]])
                dp[i] -= dp[last[s[i]] - 1];
            if(dp[i] < 0)
                dp[i] += M;
            else if(dp[i] >= M)
                dp[i] -= M;
            last[s[i]] = i;
        }
        //printf("%lld\n", dp[--i]-1);
        int ans = dp[--i]-1;
        put_i(ans);
    }
    return 0;
}