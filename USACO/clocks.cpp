/*
ID: saikira2
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <ctime>
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

ofstream fout ("clocks.out");
ifstream fin ("clocks.in");

string moves[9] = {"ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};

bool apply(int x[], int clocks[]){
    int temp[9];
    string seq = "";
    forn(i, 9){
        temp[i] = clocks[i];
        if(x[i] > 0){
            forn(k, x[i])
                seq = seq + (char)( i+1+'0' );
            string move = moves[i];
            int sz = move.size();
            int add = x[i]*3;
            forn(k, sz)
                clocks[ move[k]-'A' ] = (clocks[ move[k]-'A' ]+add)%12;
        }
    }

    int seqsz = seq.size();
    /*
    forn(i, seqsz){
        
    }
    */
    int num = 0;
    forn(i, 9){
        if(clocks[i]%12 == 0)
            num++;
        clocks[i] = temp[i];
    }
    if(num==9){
        forn(i, seqsz)
            fout << seq[i] << " ";
        fout << endl;
        return true;
    }
    return false;
}

bool check(int x[], int clocks[]){
    //check if all are 12's
    int num = 0;
    forn(i, 9){
        if(clocks[i]%12 == 0)
            num++;
    }
    
    int ans[30];
    int ans_l = 0;
    if(num==9){
        forn(i, 9){
            if(x[i] > 0){
                forn(k, x[i])
                    ans[ans_l++] = i+1;
            }
        }
        forn(i, ans_l-1)
            fout << ans[i] << " ";
        fout << ans[ans_l-1] << endl;
        return true;
    }
    return false;
}

int main(){
    clock_t t1,t2;
    t1=clock();
    int tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8, tmp9;
    int clocks[9];
    forn(i, 9)
        fin >> clocks[i];
    forn(x1,4){ forn(x2,4){ forn(x3,4){ forn(x4,4){ forn(x5,4){ forn(x6,4){ forn(x7,4){ forn(x8,4){ forn(x9,4){
                                        tmp1 = clocks[0];
                                        clocks[0] = clocks[0] + 3* (x1+x2+x4);

                                        tmp2 = clocks[1];
                                        clocks[1] = clocks[1] + 3*(x1+x2+x3+x5);

                                        tmp3 = clocks[2];
                                        clocks[2] = clocks[2] + 3*(x2+x3+x6);

                                        tmp4 = clocks[3];
                                        clocks[3] = clocks[3]+ 3*(x1+x4+x5+x7);

                                        tmp5 = clocks[4];
                                        clocks[4] = clocks[4]+ 3*(x1+x3+x5+x7+x9);

                                        tmp6 = clocks[5];
                                        clocks[5] = clocks[5] + 3*(x3+x5+x6+x9);

                                        tmp7 = clocks[6];
                                        clocks[6] = clocks[6]+ 3*(x4+x7+x8);

                                        tmp8 = clocks[7];
                                        clocks[7] = clocks[7]+ 3*(x5+x7+x8+x9);
                                        
                                        tmp9 = clocks[8];
                                        clocks[8] = clocks[8]+ 3*(x6+x8+x9);

                                        //check
                                        int x[] = {x1,x2,x3,x4,x5,x6,x7,x8,x9};                                        
                                        if( check(x, clocks) ){
                                            t2=clock();
                                            float diff ((float)t2-(float)t1);
                                            float seconds = diff / CLOCKS_PER_SEC;
                                            //cout << seconds << endl;
                                            return 0;
                                        }
                                        //end of check
                                        clocks[0] = tmp1;
                                        clocks[1] = tmp2;
                                        clocks[2] = tmp3;
                                        clocks[3] = tmp4;
                                        clocks[4] = tmp5;
                                        clocks[5] = tmp6;
                                        clocks[6] = tmp7;
                                        clocks[7] = tmp8;
                                        clocks[8] = tmp9;
                                    }                                    
                                }                                
                            }                            
                        }                        
                    }                    
                }                
            }            
        }        
    }
    return 0;
}