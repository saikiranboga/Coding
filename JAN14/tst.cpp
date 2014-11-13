#include <stack>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <stdlib.h>
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


char arr[1005][1005];
uint32_t mat[1005][1005],refarr[1005][1005],anything[1005];

struct query
{
	uint32_t l;
	uint32_t h;
	uint32_t number;
};

int compare(const void *a,const void *b)
{
	uint32_t y1=((struct query*)a)->l;
	uint32_t y2=((struct query*)b)->l;
	if(y1>y2)
		return 1;
	else if(y1<y2)
		return -1;
	else
	{
		y1=((struct query*)a)->h;
		y2=((struct query*)b)->h;
		return y1-y2;
	}
}

uint32_t getMaxArea(uint32_t hist[], uint32_t n)
{
    // Create an empty stack. The stack holds indexes of hist[] array
    // The bars stored in stack are always in increasing order of their
    // heights.
    stack<uint32_t> s;
 
    uint32_t max_area = 0; // Initalize max area
    uint32_t tp;  // To store top of stack
    uint32_t area_with_top; // To store area with top bar as the smallest bar
 
    // Run through all bars of given histogram
    uint32_t i = 0;
    while (i < n)
    {
        // If this bar is higher than the bar on top stack, push it to stack
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
 
        // If this bar is lower than top of stack, then calculate area of rectangle
        // with stack top as the smallest (or minimum height) bar. 'i' is
        // 'right index' for the top and element before top in stack is 'left index'
        else
        {
            tp = s.top();  // store the top index
            s.pop();  // pop the top
 
            // Calculate the area with hist[tp] stack as smallest bar
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
            // update max area, if needed
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
 
    // Now pop the remaining bars from stack and calculate area with every
    // popped bar as the smallest bar
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
 
    return max_area;
}


int main()
{
	uint32_t n,m,k,i,j,x,y,q;
	n = g_fi.ReadNext();
	m = g_fi.ReadNext();
	k = g_fi.ReadNext();
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			arr[i][j]='s';
	for(i=0;i<k;i++)
	{
		x = g_fi.ReadNext();
		y = g_fi.ReadNext();
		arr[x-1][y-1]='d';
	}
	q = g_fi.ReadNext();
	uint32_t ans[q];
	struct query queries[q];
	for(i=0;i<q;i++)
	{
		x = g_fi.ReadNext();
		y = g_fi.ReadNext();
		x--;y--;
		queries[i].l=x;
		queries[i].h=y;
		queries[i].number=i;
	}
	if(q>1)
		qsort(queries,n,sizeof(struct query),compare);
	for(i=0;i<q;i++)
	{
		uint32_t l1=queries[i].l;
		uint32_t j=i+1;
		while(j<q&&queries[j].l==l1)
		{
			j++;
		}
		uint32_t h1=queries[j-1].h;
		for(x=0;x<m;x++)
			refarr[l1][x]=arr[l1][x]=='s'?1:0;
		for(x=l1+1;x<=h1;x++)
		{
			for(y=0;y<m;y++)
			{
				refarr[x][y]=arr[x][y]=='s'?refarr[x-1][y]+1:0;
			}
		}
		for(x=l1;x<=h1;x++)
		{
			anything[x]=getMaxArea(refarr[x],m);
		}
		uint32_t maxnum=0,y=l1;
		for(x=i;x<j;x++)
		{
			if(queries[x].h>=y)
			{
				for(;y<=queries[x].h;y++)
				{
					maxnum=anything[y]>maxnum?anything[y]:maxnum;
				}
			}
			ans[queries[x].number]=maxnum;
		}
		i=j-1;
	}
	for(i=0;i<q;i++)
		g_fo.PrintUint(ans[i], '\n');
	g_fo.Flush();
	return 0;
}