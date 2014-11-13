#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>

#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <stdint.h>
#include <unistd.h>
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

using namespace std;
#define mod 1000000007

//ofstream fout ("LMATRIX2.out");
//ifstream fin ("test_cases.out");


class FastInput {
  public:
    FastInput() {
      m_dataOffset = 0;
      m_dataSize = 0;
      m_v = 0x80000000;
    }
    uint32_t ReadNext() {
      if (m_dataOffset == m_dataSize) {
        int r = read(0, m_buffer, sizeof(m_buffer));
        if (r <= 0) return m_v;
        m_dataOffset = 0;
        m_dataSize = 0;
        int i = 0;
        if (m_buffer[0] < '0') {
          if (m_v != 0x80000000) {
            m_data[m_dataSize++] = m_v;
            m_v = 0x80000000;
          }
          for (; (i < r) && (m_buffer[i] < '0'); ++i);
        }
        for (; i < r;) {
          if (m_buffer[i] >= '0') {
            m_v = m_v * 10 + m_buffer[i] - 48;
            ++i;
          } else {
            m_data[m_dataSize++] = m_v;
            m_v = 0x80000000;
            for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
          }
        }
      }
      return m_data[m_dataOffset++];
    }
  public:
    uint8_t m_buffer[32768];
    uint32_t m_data[16384];
    size_t m_dataOffset, m_dataSize;
    uint32_t m_v;
};
class FastOutput {
  public:
    FastOutput() {
      m_dataOffset = 0;
    }
    ~FastOutput() {
    }
    void Flush() {
      if (m_dataOffset) {
        if (write(1, m_data, m_dataOffset));
        m_dataOffset = 0;
      }
    }
    void PrintUint(uint32_t v, char d) {
      if (m_dataOffset + 11 > sizeof(m_data)) Flush();
      if (v < 100000) {
        if (v < 1000) {
          if (v < 10) {
            m_data[m_dataOffset + 0] = v + 48;
            m_dataOffset += 1;
          } else if (v < 100) {
            m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
            m_data[m_dataOffset + 0] = v + 48;
            m_dataOffset += 2;
          } else {
            m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
            m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
            m_data[m_dataOffset + 0] = v + 48;
            m_dataOffset += 3;
          }
        } else {
          if (v < 10000) {
            m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 0] = v + 48;
            
            m_dataOffset += 4;
            
          } else {
            
            m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 0] = v + 48;
            
            m_dataOffset += 5;
            
          }
          
        }
        
      } else {
        
        if (v < 100000000) {
          
          if (v < 1000000) {
            
            m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 0] = v + 48;
            
            m_dataOffset += 6;
            
          } else if (v < 10000000) {
            
            m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 0] = v + 48;
            
            m_dataOffset += 7;
            
          } else {
            
            m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 0] = v + 48;
            
            m_dataOffset += 8;
            
          }
          
        } else {
          
          if (v < 1000000000) {
            
            m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 0] = v + 48;
            
            m_dataOffset += 9;
            
          } else {
            
            m_data[m_dataOffset + 9] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
            
            m_data[m_dataOffset + 0] = v + 48;
            
            m_dataOffset += 10;
            
          }
          
        }
        
      }
      
      m_data[m_dataOffset++] = d;
      
    }
    
    void PrintChar(char d) {
      
      if (m_dataOffset + 1 > sizeof(m_data)) Flush();
      
      m_data[m_dataOffset++] = d;
      
    }
    
    void ReplaceChar(int offset, char d) {
      
      m_data[m_dataOffset + offset] = d;
      
    }
    
    
    
  public:
    
    uint8_t m_data[32768];
    
    size_t m_dataOffset;
    
};

FastInput g_fi;
FastOutput g_fo;

typedef struct info
{
    int x1, x2, y1, y2, k;
}info;

int main(){
    ios_base::sync_with_stdio(false);
    double score = 0.0;
    uint32_t tmp;
        int n, m;
        tmp = g_fi.ReadNext();
        n = tmp;
        tmp = g_fi.ReadNext();
        m = tmp;
        int P[n+1][m+1];
        int A[n+1][m+1];
        vector<info> ans;
        fori(i, 1, n)
            fori(j, 1, m){
                tmp = g_fi.ReadNext();
                P[i][j] = tmp;
            }

        int mx = 0;
        int k_all = 0;
        fori(i, 1, n){
            fori(j, 1, m){
                tmp = g_fi.ReadNext();
                A[i][j] = tmp;
                if(A[i][j] == 0)
                    mx++;
            }
        }

        //checking for a global k which when added to the 
        //entire matrix increases the number of zeros 
        fori(k, 1, 6000){
            int cnt = 0;
            fori(i, 1, n){
                fori(j, 1, m){
                    if( (A[i][j]+k)%P[i][j] == 0 )
                        cnt++;
                }
            }
            if(cnt > mx){
                k_all = k;
                mx = cnt;
            }
        }

        fori(i, 1, n){
            fori(j, 1, m){
                A[i][j] = (A[i][j]+k_all)%P[i][j];
            }
        }

        info all;
        all.x1 = 1, all.y1 = 1, all.x2 = n, all.y2 = m, all.k = k_all;
        ans.pb(all);
        //end

        //checking all row and col sub-matrices that may mod to 0 when added to a k
        fori(k, 1, 10){
            int Ks[n+1][m+1];
            //rows
            fori(i, 1, n){
                fori(j, 1, m)
                    Ks[i][j] = (A[i][j]+k)%P[i][j];
                int zeros = 0;
                int new_zeros = 0;
                fori(j, 1, m){
                    if(A[i][j] == 0)
                        zeros++;
                    if(Ks[i][j]==0)
                        new_zeros++;
                }
                if(new_zeros > zeros){
                    info add;
                    add.x1 = i; add.y1 = 1; add.x2 = i; add.y2 = m; add.k = k;
                    ans.pb(add);
                    fori(j, 1, m){
                        A[i][j] = (A[i][j]+k)%P[i][j];
                    }
                }
            }

            //cols
            fori(j, 1, m){
                fori(i, 1, n){
                    Ks[i][j] = (A[i][j]+k)%P[i][j];
                    int zeros = 0;
                    int new_zeros = 0;
                    fori(i, 1, n){
                        if(A[i][j] == 0)
                            zeros++;
                        if(Ks[i][j]==0)
                            new_zeros++;
                    }
                    if(new_zeros > zeros){
                        info add;
                        add.x1 = 1; add.y1 = j; add.x2 = n; add.y2 = j; add.k = k;
                        ans.pb(add);
                        fori(i, 1, n)
                            A[i][j] = (A[i][j]+k)%P[i][j];
                    }
                }
            }
        }
        // end

        //checking for 3x3 sub-matrices that may mod to 0 when added to a k
        fori(k, 1, 500){
            int Ks[n+1][m+1];
            fori(i, 1, n){
                fori(j, 1, m){
                    Ks[i][j] = (A[i][j]+k)%P[i][j];
                }
            }

            fori(i, 1, n-2){
                fori(j, 1, m-2){
                    if( (A[i][j]>0) && (Ks[i][j] == 0) ){
                        int flag = 1;
                        fori(a, i,i+2){
                            fori(b, j, j+2){
                                if(A[a][b]==0){
                                    flag = 0;
                                    break;
                                }
                            }
                            if(!flag)
                                break;
                        }

                        if(flag){
                            fori(a, i,i+2){
                                fori(b, j, j+2){
                                    if(Ks[a][b]!=0){
                                        flag = 0;
                                        break;
                                    }
                                }
                                if(!flag)
                                    break;
                            }
                        }

                        if(flag){
                            info add;
                            add.x1 = i; add.y1 = j; add.x2 = i+2; add.y2 = j+2; add.k = k;
                            ans.pb(add);
                            fori(a, i,i+2)
                                fori(b, j, j+2)
                                    A[a][b] = (A[a][b]+k)%P[a][b];
                        }
                    }
                }
            }
        }
        // end

        //checking for 2x2 sub-matrices that may mod to 0 when added to a k
        fori(k, 1, 6000){
            int Ks[n+1][m+1];
            fori(i, 1, n){
                fori(j, 1, m){
                    Ks[i][j] = (A[i][j]+k)%P[i][j];
                }
            }

            fori(i, 1, n-1){
                fori(j, 1, m-1){
                    if( (A[i][j]>0) && (Ks[i][j] == 0) ){
                        int a1 = A[i+1][j];
                        int b1 = A[i][j+1];
                        int c1 = A[i+1][j+1];

                        int a = Ks[i+1][j];
                        int b = Ks[i][j+1];
                        int c = Ks[i+1][j+1];
                        if( (a1!=0) && (b1!=0) && (c1!=0) && (a==0) && (b==0) && (c==0) ){
                            info add;
                            add.x1 = i; add.y1 = j; add.x2 = i+1; add.y2 = j+1; add.k = k;
                            ans.pb(add);
                            A[i][j] = ( A[i][j] + k )%P[i][j];
                            A[i+1][j] = ( A[i+1][j] + k )%P[i+1][j];
                            A[i][j+1] = ( A[i][j+1] + k )%P[i][j+1];
                            A[i+1][j+1] = ( A[i+1][j+1] + k )%P[i+1][j+1];
                        }
                    }
                }
            }
        }
        // end

        fori(i, 1, n){
            fori(j, 1, m){
                if(A[i][j] != 0){
                    info f;// = (*info)malloc(sizeof(info));
                    f.x1 = i;
                    f.x2 = i;
                    f.y1 = j;
                    f.y2 = j;
                    f.k = P[i][j] - A[i][j];
                    A[i][j] = 0;
                    ans.pb(f);
                }
            }
        }


        ll sum = 0;
        fori(i, 1, n){
            fori(j, 1, m){
                sum += A[i][j];
            }
        }

        assert(sum==0);

        int sz = ans.size();

        assert(sz<=(n*m));

        //cout << sz << endl;
        g_fo.PrintUint(sz, '\n');
        forn(i, sz){
            //cout << ans[i].x1 << " " << ans[i].y1 << " " << ans[i].x2 << " " << ans[i].y2 << " " << ans[i].k << endl;
            g_fo.PrintUint(ans[i].x1, ' ');
            g_fo.PrintUint(ans[i].y1, ' ');
            g_fo.PrintUint(ans[i].x2, ' ');
            g_fo.PrintUint(ans[i].y2, ' ');
            g_fo.PrintUint(ans[i].k, '\n');
        }

        score = score + ((double)(sz*100))/((double)(n*m));
    g_fo.Flush();
    return 0;
}
