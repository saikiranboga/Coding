/*
ID: freeman92
PROG: CHSEQ22
LANG: C++
*/
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
#include <stdio.h>
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

#define MOD 1000000007
#define Mx 100010

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


vector<int> graph[Mx];
int visited[Mx];
int n, m;

ll power(int base, int p){
    ll ret;
    if(p==0 || p==1)
        return base;
    ret = power(base, p/2);
    ret = ( ((ret)%MOD )* ((ret)%MOD) )%MOD;
    if(p&1){
        ret = (ret*base)%MOD;
    }
    return ret;
}

//returns number of components
int dfs(int v){
    visited[v] = 1;
    int ret = 1;
    int sz = graph[v].size();
    forn(i, sz){
        if(!visited[ graph[v][i] ]){
            ret += dfs( graph[v][i] );
        }
    }
    return ret;
}

int call_dfs(){
    int ret = 0;
    memset(visited, 0, sizeof(visited));
    fori(i, 0, n){
        if(!visited[i]){
            ret += (dfs(i)-1 );
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    vector<pt> ints;
    uint32_t tmp;
    tmp = g_fi.ReadNext();
    n = tmp;
    tmp = g_fi.ReadNext();
    m = tmp;
    int x, y;
    forn(i, m){
        //cin >> x >> y;
        tmp = g_fi.ReadNext();
        x = tmp;
        tmp = g_fi.ReadNext();
        y = tmp;
        //decreasing x by 1, self loops
        x--;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    int ans = call_dfs();

    ans = power(2, ans);

    g_fo.PrintUint(ans, '\n');
    g_fo.Flush();
	return 0;
}