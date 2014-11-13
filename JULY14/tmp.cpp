using namespace std;

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iterator>
#include<sstream>
#include<fstream>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; i++)
#define rev(i,a,b) for(i=a; i>=b; i--)
#define scan(n) scanf("%d", &n)
#define scans(s) scanf("%s", s)
#define scanc(c) scanf("%c", &c)
#define scanp(f) scanf("%f", &f)
#define scanll(l) scanf("%lld", &l)
#define scanllu(u) scanf("%llu", &u)
#define print(n) printf("%d\n", n)
#define prints(s) printf("%s\n", s)
#define printc(c) printf("%c\n", c)
#define printp(f) printf("%f\n", f)
#define printll(l) printf("%lld\n", l)
#define printllu(u) printf("%llu\n", u)
#define nline printf("\n")
#define mclr(strn) strn.clear()
#define ignr cin.ignore()
#define MOD 1000000007
#define ll long long int
#define u64 unsigned long long int

int p[1000006], mark[2100];
int taken[2100];
ll mat[1003][1003];

int main() 
{
    int i, j, cases, k;
    ll n, m;
    int issol, done, given, ind, temp;
    ll limit;
    int var;
    scan(cases);
    wl(cases)
    {
        issol=1; 
        fl(i,0,2100)
            taken[i]=0;
        done=1;
        cin>>n>>m;
        fl(i,0,n)
            cin>>p[i];
        limit=((m*m)/2);
        fl(i,0,n)
        {
            if(taken[i]==0)
            {
                given=0;
                ind=i;
                while(taken[ind]==0)
                {
                    given++;
                    taken[ind]=1;
                    mark[given]=ind;
                    ind=p[ind];
                }
                int kk = (m + given - 1) / given;
                if(given<=2 || m<=2*kk)
                {
                    issol=0;
                    break;
                }
                fl(j,1,m+1)
                {
                    temp=(j-1)%given;
                    fl(k,1,given+1)
                    {
                        mat[mark[k]][j]=temp+done;
                        temp=((temp-1)+given)%given;
                    }
                    done+=given;
                }
            }
        }
        if(issol!=0){
           fl(i,0,n)
            {
                var=0;
                fl(j,1,m+1)
                {
                    if(mat[i][j]>=mat[p[i]][j])
                        var+=j;
                    else
                        var+=j-1;
                }
                if(var<=limit)
                {
                    issol=0;
                    break;
                }
            }
        }

        if(issol==0)
        {
            cout<<"No Solution";
            nline;
            continue;
        }

        fl(i,0,n)
        {
            fl(j,1,m+1)
            {
                cout<<mat[i][j] << " ";
            }
                nline;
        }
    }
    return 0;
}