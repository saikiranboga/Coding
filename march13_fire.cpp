#include <iostream>
#include <cstdio>
using namespace std;

/* Input Output Function */
#define INPUT fread(IBUF, 1, BUFSIZE, stdin);
#define BUFSIZE (1<<26)
char IBUF[BUFSIZE+1], *inputptr=IBUF, OBUF[BUFSIZE+1], *outputptr=OBUF, DIP[20];
#define DIG(a) (((a)>='0')&&((a)<='9'))//::DIG(
#define getChar(t) {t=*inputptr++;}//::getChar(
template<class T>inline bool getInt(T &j) {j=0;int _t;getChar(_t);if(_t==0)return false;char sign;while(!DIG(_t)&&_t!=0){sign=_t;getChar(_t);}while(DIG(_t)){j=10*j+(_t-'0');getChar(_t);}if(sign == '-') j = -j;*inputptr--;return j==0&&_t==0?false:true;}//::getInt(
inline bool getString(char *s) {char _c;getChar(_c);if(_c==0)return false;while(_c==10||_c==32)getChar(_c);while(_c != 10&&_c != 32&&_c!=0){*s++=_c;getChar(_c)}*s=0;inputptr--;return s[0]==0&&_c==0?false:true;}
template<class T> inline void putInt(T x, char n=0) {int y, dig=0;while(x){y=x%10;DIP[dig++]=y+'0';x/=10;}while (dig--) *outputptr++=DIP[dig];n?*outputptr++=n:0;}
template<class T> inline void putString(T *s, char n=0){while(*s)*outputptr++=*s++;n?*outputptr++=n:0;}
#define putLine() {*outputptr++=10;}
#define OUTPUT fputs(OBUF, stdout);

int parent[100005];
int find_parent( int m)
{
	int k = m;
	while ( parent[m] != m) //finding parent
	{
		m = parent[m];
	}
	return m;
}

void chang(int k, int m)
{
    while ( k != m) //connecting each vertices to one parent
	{
        int l = parent[k];
        parent[k] = m;
        k = l;
	}
}
int main()
{
    //freopen("input.txt","r",stdin);
    INPUT;
	int t;
    getInt(t);
	while ( t-- ) {
		int n,e,a,b;
		int c=0;
		getInt(n);
		for ( int i = 0; i <=n; i++)
			parent[i] = i;
        getInt(e);
		for ( int i = 0; i < e;i++)
		{
			getInt(a); getInt(b);
			int r = find_parent(a);
			chang(a,r);
			int s = find_parent(b);
			chang(b,s);
			parent[s] = r;
        }
		for ( int i = 1; i <= n;i++)
		{
		  //		  putInt(parent[i]);
			if ( parent[i] == i)
			  c++;
		}
		putInt(c);		
		putLine();
	}
	OUTPUT;
	return 0;
}








