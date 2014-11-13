/*
Segment Tree Lazy propogation implementation
*/
#include<bits/stdc++.h>
#include <stdint.h>
#include <unistd.h>
using namespace std;

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

class Node {
public:
    int numMod[3];
    int lazy;
};

class SegTree {
public:
    const static int MAXN = 100005;
    Node* tree[2 * MAXN];
    int A[MAXN];
    int N;

    SegTree(int NN){
        N = NN;
    }

    inline void initialize(int node_num, int st, int ed) {
        tree[node_num] = new Node();
        tree[node_num]->numMod[0] = ed-st+1;
        if (st != ed) {
            int mid = (st + ed) >> 1;
            initialize(node_num<<1, st, mid);
            initialize(node_num<<1 | 1, mid + 1, ed);
        }
        return;
    }

    inline void refresh(int node_num, int st, int ed){
        if(tree[node_num]->lazy>0){
            int tmp;
            if(tree[node_num]->lazy == 1){
                tmp = tree[node_num]->numMod[0];
                tree[node_num]->numMod[0] = tree[node_num]->numMod[2];
                tree[node_num]->numMod[2] = tree[node_num]->numMod[1];
                tree[node_num]->numMod[1] = tmp;
            }
            else{
                tmp = tree[node_num]->numMod[0];
                tree[node_num]->numMod[0] = tree[node_num]->numMod[1];
                tree[node_num]->numMod[1] = tree[node_num]->numMod[2];
                tree[node_num]->numMod[2] = tmp;
            }

            if(st!=ed){
                tree[node_num<<1]->lazy += tree[node_num]->lazy;
                if(tree[node_num<<1]->lazy >= 3)
                    tree[node_num<<1]->lazy -= 3;
                tree[node_num<<1 | 1]->lazy += tree[node_num]->lazy;
                if(tree[node_num<<1 | 1]->lazy >= 3)
                    tree[node_num<<1 | 1]->lazy -= 3;
            }
            tree[node_num]->lazy = 0;
        }
        return;
    }

    inline void update(int node_num, int st, int ed, int i, int j) {

        // query seg doesn't lie in the current segment
        if (st>ed || i > ed || j < st){
            refresh(node_num, st, ed);
            return;
        }

        // current segment lies entirely in the query interval
        // change lazy flag and refresh node_num
        if(st>=i && ed<=j){
            tree[node_num]->lazy += 1;
            if(tree[node_num]->lazy >= 3)
                tree[node_num]->lazy -= 3;
            refresh(node_num, st, ed);
            return;
        }

        int mid = (st+ed) >> 1;

        // cur segment overlaps query interval.
        
        // refresh the current node
        refresh(node_num, st, ed);

        // call updates on children
        update(node_num << 1, st, mid, i, j);
        update(node_num << 1 | 1, mid + 1, ed, i, j);

        // then update the node value, if not leaf
        if(st!=ed){
            for(int i=0;i<3;i++)
                tree[node_num]->numMod[i] = tree[node_num << 1]->numMod[i] + tree[node_num << 1 | 1]->numMod[i];
        }
        
        return;
    }

    inline int query(int node_num, int st, int ed, int i, int j) {
        // query seg out of current seg
        if(st>ed || i>ed || j<st)
            return 0;

        // refresh the current seg
        refresh(node_num, st, ed);

        // query seg lies entirely in the cur seg, then return 
        // the sum (this seg is not lazy, as we have already refreshed it above)
        if(st>=i && ed<=j)
            return tree[node_num]->numMod[0];

        int mid = (st+ed) >> 1;
        
        if(j<=mid)
            return query(node_num << 1, st, mid, i, j); // lies to left
        else if(i>mid)
            return query(node_num << 1 | 1, mid+1, ed, i, j); // lies to right
        else
            return query(node_num << 1, st, mid, i, j) + query(node_num << 1 | 1, mid+1, ed, i, j); // cur seg overlaps query seg
    }
};

int main(){
    
    uint32_t tmp;
    int N, Q, type, x, y;
    //scanf("%d %d",&N, &Q);
    tmp = g_fi.ReadNext();
    N = tmp;
    tmp = g_fi.ReadNext();
    Q = tmp;
    SegTree* ST = new SegTree(N);

    //for(int i=1;i<=N;i++)
    //    ST->A[i] = 0;

    ST->initialize(1, 1, N);

    while(Q--) {
        //scanf("%d %d %d", &type, &x, &y);
        tmp = g_fi.ReadNext();
        type = tmp;

        tmp = g_fi.ReadNext();
        x = tmp;

        tmp = g_fi.ReadNext();
        y = tmp;

        x++, y++;
        if(x>y)
            swap(x,y);
        if(type==0)
            ST->update(1, 1, N, x, y);
        else {
            int ans = ST->query(1, 1, N, x, y);
            //printf("%d\n",ans);
            g_fo.PrintUint(ans, '\n');
        }
    }
    g_fo.Flush();
    return 0;
}