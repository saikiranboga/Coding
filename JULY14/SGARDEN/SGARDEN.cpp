#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef long long int ll;

#define M 1000000007
#define MAXN 100010
#define NPR 65

int primes[NPR] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
                     47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 
                     103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 
                     157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
                     211, 223, 227, 229, 233, 239, 241, 251, 257, 263,
                     269, 271, 277, 281, 283, 293, 307, 311, 313};

int facts[MAXN][2];
int more;

// calculates the base raised to a power, using binary exponentiation
ll power(ll base, ll pw){
    if(pw==0)
        return 1;
    if(pw==1)
        return base;
    ll ret = power(base, pw/2);
    ret = (ret*ret)%M;
    if(pw%2!=0)
        ret = (ret*base)%M;
    return ret;
}

// calculates the gcd of two numbers
ll gcd(ll a, ll b) 
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

ll mod_of_lcm(vector<ll> a)
{
    //total number of cycles found
    ll n = a.size();

    more = 0;

    // for each of the elements in the array a
    // i.e. for each of the numbers on which lcm is to be perfomred 
    for(ll i=0;i<n;i++)
    {

        // prime factorization if the number is not 1
        if(a[i]!=1)
        {
            ll cur_n = a[i];

            // prime factorize the number
            for(int j=0;j<NPR;j++){
                int cur_pr = primes[j];
                int cur_pr_pw = 0;
                
                // get the power of this prime factor in the actual number
                while(cur_n%cur_pr == 0){
                    cur_pr_pw++;
                    cur_n /= cur_pr;
                }
                
                // if the power of this prime factor is greater than the
                // one already stored then replace it
                if(facts[j][1]<cur_pr_pw)
                    facts[j][1] = cur_pr_pw;
            }

            // we have only factorized the number by the first 26 prime numbers
            // the number may have other primes in it.
            // (But the number cannot contain 3 - three digit prime factors in it, 
            // since the given range of numbers is <= 10^5 )
            // so we store them as is as factors.
            if(cur_n>1){
                bool exists = false;
                for(int j=0; j<NPR+more; j++){
                    if(cur_n == facts[j][0]){
                        exists = true;
                        break;
                    }
                }
                if(!exists){
                    facts[NPR+more][0] = cur_n;
                    facts[NPR+more][1] = 1;
                    more++;
                }
            }
        }
    }

    ll ans = 1;

    for(int i=0;i<NPR+more;i++){
        if(facts[i][1]!=0)
            ans = (ans*power(facts[i][0], facts[i][1]))%M;
    }

    return ans;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        memset(facts,0,sizeof(facts));
        for(int i=0;i<NPR;i++)
            facts[i][0] = primes[i];
        ll n;
        cin >> n;
        ll pos[n];
        bool vis[n];
        for(int i=0;i<n;i++){
            cin >> pos[i];
            pos[i] -= 1;
            vis[i] = false;
        }

        ll ans = 1;
        vector<ll> cycle_lens;
        ll cycle_start, next, cycle_len;
        for(int i=0;i<n;i++){
            if(vis[i]==true)
                continue;
            cycle_start = pos[i];
            next = cycle_start;
            cycle_len = 0;
            while(true){
                cycle_len++;
                vis[next] = true;
                next = pos[next];
                if(next==cycle_start)
                    break;
            }
            cycle_lens.push_back(cycle_len);
        }
        cout << mod_of_lcm(cycle_lens) << endl;
    }
    return 0;
}