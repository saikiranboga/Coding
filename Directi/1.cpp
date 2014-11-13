#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cstring>
#include <cmath>
#include <stdlib.h>
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

int main(){
    ios_base::sync_with_stdio(false);
    uint32_t n, v;
    //cin >> n;
    //cin >> v;
    n = g_fi.ReadNext();
    v = g_fi.ReadNext();
    vector<int> viewed;
    uint32_t tmp;
    forn(i, v){
        tmp = g_fi.ReadNext();
        viewed.pb(tmp);
    }

    uint32_t l;
    //cin >> l;
    l = g_fi.ReadNext();
    uint32_t list_size[l];
    vector<int> list[l];

    int excl[n][l];
    memset(excl, 0, sizeof(excl) );

    forn(i, l){
        tmp = g_fi.ReadNext();
        list_size[i] = tmp;
        forn(j, list_size[i]){
            tmp = g_fi.ReadNext();
            list[i].pb(tmp);
            excl[tmp][i] = 1;
        }
    }

    uint32_t p;
    int compr = 0;
    //cin >> p;
    p = g_fi.ReadNext();
    forn(i, p){
        uint32_t in_sz, ex_sz;
        //cin >> in_sz;
        in_sz = g_fi.ReadNext();
        uint32_t in[in_sz];
        if(in_sz > 0)
            forn(j,in_sz)
                //cin >> in[j];
                in[j] = g_fi.ReadNext();

        //cin >> ex_sz;
        ex_sz = g_fi.ReadNext();
        uint32_t ex[ex_sz];

        int check = 0;

        if(in_sz==0 && ex_sz==0){
        }
        if( !check && in_sz > 0){
            forn(k, v){
                int flag = 0;
                forn(j, in_sz){
                    if( excl[ viewed[k] ][ in[j] ]==1 ){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    //cout << "compr\n";
                    compr++;
                    check = 1;
                    break;
                }
            }

        }
        if(!check && ex_sz > 0){
            forn(j,ex_sz)
                ex[j] = g_fi.ReadNext();
                //cin >> ex[j];
            int flag = 0;
            forn(j, v){
                forn(k, ex_sz){
                    if( excl[ viewed[j] ][ ex[k] ] == 1){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1)
                    break;
            }
            if(flag==1){
                compr++;
                //cout << "compr\n";
            }
        }
    }

    //cout << compr << endl;
    g_fo.PrintUint(compr, '\n');
    g_fo.Flush();
	return 0;
}