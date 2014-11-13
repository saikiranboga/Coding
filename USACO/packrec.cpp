/*
ID: saikira2
PROG: packrec
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
#define max2(a,b) max(a, b)
#define max3(a,b,c) max(a, max(b, c))
#define max4(a,b,c,d) max(a, max(b, max(c,d)))

typedef pair<int, int> pt;

typedef struct rect{
    int wh[2];
    int area;
}rect;

bool comp(rect a, rect b){
    if(a.area == b.area)
        return a.wh[0] < b.wh[0];
    else
        return a.area < b.area;
}

int main(){
	ofstream fout ("packrec.out");
    ifstream fin ("packrec.in");
    rect r[4];
    forn(i, 4){
        //r[i] = (rect*)malloc(sizeof(rect));
        fin >> r[i].wh[0] >> r[i].wh[1];
        r[i].area = r[i].wh[0] * r[i].wh[1];
    }

    int rs[] = {0,1,2,3};

    int mn = 10000;
    vector<rect> ans;
    int w1, w2, w3, w4, h1, h2 ,h3, h4, w, h;
    do{
        //fout << rs[0] << ' ' << rs[1] << ' ' << rs[2] << ' ' << rs[3] << endl;
        forn(i, 16){
            int t;
            t = (int)(bool)(i&1);
            w1 = r[rs[0]].wh[t];    h1 = r[rs[0]].wh[1-t];

            t = (int)(bool)(i&2);
            w2 = r[ rs[1] ].wh[t];    h2 = r[ rs[1] ].wh[1-t];

            t = (int)(bool)(i&4);
            w3 = r[ rs[2] ].wh[t];    h3 = r[ rs[2] ].wh[1-t];

            t = (int)(bool)(i&8);
            w4 = r[ rs[3] ].wh[t];    h4 = r[ rs[3] ].wh[1-t];
            
            /*
            fout << "dims " << i << endl;
            fout << w1 << ' ' << h1 << endl;
            fout << w2 << ' ' << h2 << endl;
            fout << w3 << ' ' << h3 << endl;
            fout << w4 << ' ' << h4 << endl << endl;
            */

            //pos1
            w = w1+w2+w3+w4;
            h = max4(h1, h2, h3, h4);
            if(w*h <= mn){
                rect r_tmp;// = (rect*)malloc(sizeof(rect));
                r_tmp.wh[0] = min(w,h);
                r_tmp.wh[1] = (w*h)/r_tmp.wh[0];
                r_tmp.area = w*h;
                ans.pb( r_tmp );

                mn = r_tmp.area;
            }

            //pos2
            w = max(w1+w2+w3, w4);
            h = max3(h1,h2,h3) + h4;
            if(w*h <= mn){
                rect r_tmp;// = (rect*)malloc(sizeof(rect));
                r_tmp.wh[0] = min(w,h);
                r_tmp.wh[1] = (w*h)/r_tmp.wh[0];
                r_tmp.area = w*h;
                ans.pb( r_tmp );

                mn = r_tmp.area;
            }

            //pos3
            w = max(w1+w2, w3) + w4;
            h = max( max(h1,h2)+h3, h4);
            if(w*h <= mn){
                rect r_tmp;// = (rect*)malloc(sizeof(rect));
                r_tmp.wh[0] = min(w,h);
                r_tmp.wh[1] = (w*h)/r_tmp.wh[0];
                r_tmp.area = w*h;
                ans.pb( r_tmp );

                mn = r_tmp.area;
            }


            //pos4
            w = w1+ max(w2,w3) + w4;
            h = max3(h1, h2+h3, h4);
            if(w*h <= mn){
                rect r_tmp;// = (rect*)malloc(sizeof(rect));
                r_tmp.wh[0] = min(w,h);
                r_tmp.wh[1] = (w*h)/r_tmp.wh[0];
                r_tmp.area = w*h;
                ans.pb( r_tmp );

                mn = r_tmp.area;
            }

            //pos5
            w = max(w1,w2)+w3+w4;
            h = max3(h1+h2, h3, h4);
            if(w*h <= mn){
                rect r_tmp;// = (rect*)malloc(sizeof(rect));
                r_tmp.wh[0] = min(w,h);
                r_tmp.wh[1] = (w*h)/r_tmp.wh[0];
                r_tmp.area = w*h;
                ans.pb( r_tmp );

                mn = r_tmp.area;
            }

            //pos6
            h = max(h1+h3, h2+h4);
            if(h3>h2+h4)
                w = max(w3+max(w2,w4), w1);
            else if( (h3<h2+h4) && (h3>h4) )
                w = max3(w3+w4, w3+w2, w1+w2);
            else if( (h3<h4) && (h4<h1+h3) )
                w = max3(w1+w4, w3+w4, w1+w2);
            else if(h4>h1+h3)
                w = max3(w2, w4+w1, w4+w3);
            else if(h3==h4)
                w = max( w3+w4, w1+w2 );

            if(w*h <= mn){
                rect r_tmp;// = (rect*)malloc(sizeof(rect));
                r_tmp.wh[0] = min(w,h);
                r_tmp.wh[1] = (w*h)/r_tmp.wh[0];
                r_tmp.area = w*h;
                ans.pb( r_tmp );

                mn = r_tmp.area;
            }

        }
    }while(next_permutation(rs, rs+4));

    sort(ans.begin(), ans.end(), comp);

    fout << mn << endl;
    int id = 0;
    int sz = ans.size();
    int prevwh = -1;
    while(id <sz && ans[id].area==mn){
        //cout << ans[id].wh[0] << ' ' << ans[id].wh[1] << endl;
        if( (ans[id].wh[0] != prevwh ) && (ans[id].wh[1] != prevwh) ){
            fout << ans[id].wh[0] << ' ' << ans[id].wh[1] << endl;
            prevwh = ans[id].wh[0];
        }
        id++;
    }

	return 0;
}