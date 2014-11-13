#include <bits/stdc++.h>
#include <string.h>
using namespace std;

#define inf 1000000000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define VI vector<int>
#define PII pair<int, int>
#define all(v) (v.begin(), v.end())

string s1, s2;
double mem[22];
double* pos = &mem[10];
int final_pos = 0;
double ans = 0.0;

void fwd(int cur_pos, int idx){
    if(s2[idx]=='+'){
        pos[cur_pos+1] = pos[cur_pos];
        if(idx<s2.sz-1){
            pos[cur_pos] = 0;
            fwd(cur_pos+1, idx+1);
        }
        else if(cur_pos+1 == final_pos){
            ans += pos[cur_pos+1];
        }
    }
    else if(s2[idx]=='-'){
        pos[cur_pos-1] = pos[cur_pos];
        if(idx<s2.sz-1){
            pos[cur_pos] = 0;
            fwd(cur_pos-1, idx+1);
        }
        else if(cur_pos-1 == final_pos){
            ans += pos[cur_pos-1];
        }
    }
    else{
        pos[cur_pos-1] = pos[cur_pos]*0.5;
        double temp = pos[cur_pos];
        if(idx<s2.sz-1){
            pos[cur_pos] = 0;
            fwd(cur_pos-1, idx+1);
        }
        else if(cur_pos-1 == final_pos){
            ans += pos[cur_pos-1];
        }


        pos[cur_pos] = temp;
        pos[cur_pos+1] = pos[cur_pos]*0.5;
        if(idx<s2.sz-1){
            pos[cur_pos] = 0;
            fwd(cur_pos+1, idx+1);
        }
        else if(cur_pos+1 == final_pos){
            ans += pos[cur_pos+1];
        }
    }
    return;
}


int main(){
    cin >> s1 >> s2;
    
    for(int i=0; i<s1.sz; i++){
        if(s1[i]=='+')
            final_pos++;
        else
            final_pos--;
    }

    for(int i=0; i<21; i++)
        mem[i] = 0;

    pos[0] = 1;
    
    fwd(0, 0);

    cout << setprecision(10) << ans << endl;

    return 0;
}