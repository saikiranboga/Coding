/*
ID: saikira2
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

#define ll long long

#define fore(i, l, r) for(int i = (l); i < (r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define ford(i, up, bot) for(int i = (up); i > (bot); --i)
#define fordi(i, up, bot) ford(i, up, bot-1)

#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef pair<int, int> pt;

int digits[10];
int n;
int f_min, f_max;
int s_min, s_max;
int ans_min, ans_max;

bool valid(int no, int which_no){
    int num = no;
    int dig;
    bool exists;
    int len = 0;
    while(no>0){
        dig = no%10;
        no /= 10;
        exists = false;
        len++;
        forn(i, n){
            if(digits[i]==dig){
                exists = true;
                break;
            }
        }
        if(!exists)
            return false;
    }
    if(which_no == 1){
        if(len==3){
            if(f_min<=num && num<=f_max)
                return true;
            else
                return false;
        }
        else{
            return false;
        }
    }
    else if(which_no == 2){
        if(len==2){
            if(s_min<=num && num<=s_max){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else if(which_no == 3){
        if(len==4){
            if(ans_min<=num && num<=ans_max){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
}

int main(){
	ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");

    fin >> n;
    
    forn(i, n)
        fin >> digits[i];
    sort(digits, digits+n);

    ans_min = 1111*digits[0];
    ans_max = 1111*digits[n-1];

    f_min = 111*digits[0];
    f_max = 111*digits[n-1];

    s_min = 11*digits[0];
    s_max = 11*digits[n-1];

    int ans = 0;

    // loop through all possible first nos
    fori(i, f_min, f_max){
        //check if first no. is valid
        if( valid(i, 1) ){
            //multiply with all possible second nos
            fori(j, s_min, s_max){
                //cout << i << " " << j << endl;
                //check if second no. is valid
                if( valid(j, 2) ){
                    int s_sd = j%10;
                    int s_fd = j/10;
                    if( valid(i*s_sd, 1) && valid(i*s_fd, 1) && valid(i*j, 3) ){
                        ans++;
                    }
                }
            }
        }

    }

    fout << ans << endl;

	return 0;
}