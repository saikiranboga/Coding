#pragma comment(linker, "/STACK:1000000000")
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <bitset>
#include <sstream>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <set>
#include <map>
 
using namespace std;
 
#define ppb pop_back
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
 
#define inf 1000000007
#define nmax 100010
#define mmax 100010
#define eps 1e-9
 
const int Block = 600;
const bool dbg = false; //true;
 
vector < int > g[nmax], ts;
int x, y, n, m, cs[nmax], k, f, l, r, lv[nmax];
int pr[nmax], was[nmax], sz[nmax], dpth[nmax];
int tin[nmax], tout[nmax], timer;
vector < int > levels[nmax], ttime[nmax];
vector < long long > add[4 * nmax];
vector < pair < long long, int > > t[4 * nmax];
int L[nmax][17], R[nmax][17], uu[nmax], pt;
int bad[nmax], cnt[nmax];
 
void dfs(int v, int p, int dpt = 0)
{
	tin[v] = ++timer; pr[v] = p; //ts.pb(v);
	levels[dpt].pb(v); ttime[dpt].pb(timer);
	k = max(k, dpt); dpth[v] = dpt;
	for(int i = 0; i < g[v].size(); ++i)
		if(g[v][i] != p)
			dfs(g[v][i], v, dpt + 1);
	tout[v] = timer;
}
 
void use(int v, int p)
{
	cnt[v] = bad[v];
	for(int i = 0; i < g[v].size(); ++i)
		if(g[v][i] != p)
		{
			use(g[v][i], v);
			cnt[v] += cnt[g[v][i]];
		}
}
 
void build(int rr, int v, int l, int r)
{
	if(l != r)
	{
		int m = (l + r) >> 1;
		build(rr, v + v, l, m);
		build(rr, v + v + 1, m + 1, r);
		t[rr][v] = min(t[rr][v + v], t[rr][v + v + 1]);
	}
	else
		t[rr][v] = mp(cs[levels[rr][l]], l);
}
 
void push(int rr, int v, int l, int r)
{
	if(add[rr][v])
	{
		if(l != r)
		{
			add[rr][v + v] += add[rr][v];
			add[rr][v + v + 1] += add[rr][v];
		}
		t[rr][v].fs += add[rr][v];
		add[rr][v] = 0;
	}
}
 
void upd(int rr, int v, int L, int R, int l, int r, long long val)
{
	if(l > r)
		return;
	if(L == l && r == R)
	{
		add[rr][v] += val;
		push(rr, v, l, r);
		return;
	}
	int M = (L + R) >> 1;
	push(rr, v, L, R);
	push(rr, v + v, L, M);
	push(rr, v + v + 1, M + 1, R);
	if(r <= M)
		upd(rr, v + v, L, M, l, r, val);
	else if(l > M)
		upd(rr, v + v + 1, M + 1, R, l, r, val);
	else
	{
		upd(rr, v + v, L, M, l, M, val);
		upd(rr, v + v + 1, M + 1, R, M + 1, r, val);
	}
	t[rr][v] = min(t[rr][v + v], t[rr][v + v + 1]);
}
 
pair < long long, int > get(int rr, int v, int L, int R, int l, int r)
{
	push(rr, v, L, R);
	if(L == l && r == R)
		return t[rr][v];
	int M = (L + R) >> 1;
	push(rr, v + v, L, M); push(rr, v + v + 1, M + 1, R);
	if(r <= M)
		return get(rr, v + v, L, M, l, r);
	if(l > M)
		return get(rr, v + v + 1, M + 1, R, l, r);
	return min(get(rr, v + v, L, M, l, M), get(rr, v + v + 1, M + 1, R, M + 1, r));
}
 
void pre()
{
	for(int i = 0; i <= k; ++i)
	{
		sz[i] = levels[i].size();
		add[i].resize(4 * sz[i]);
		t[i].resize(4 * sz[i]);
		build(i, 1, 0, sz[i] - 1);
	}
	if(dbg)
	{
		for(int i = 0; i < levels[2].size(); ++i)
			cout << levels[2][i] << " ";
		cout << endl;
		for(int i = 1; i <= n; ++i)
			cout << tin[i] << " " << tout[i] << endl;
		cout << get(2, 1, 0, sz[2] - 1, 0, sz[2] - 1).fs << endl;
	}
}
 
bool par(int a, int b)
{
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}
 
int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &cs[i]);
	for(int i = 1; i < n; ++i)
	{
		scanf("%d%d", &x, &y);
		g[x].pb(y); g[y].pb(x);
	}
	dfs(1, 0); //reverse(ts.begin(), ts.end());
	pre();
	scanf("%d", &m);
	for(int i = 1; i <= n; ++i)
	{
		int dpt = dpth[i];
		for(int j = dpt; j < dpt + 17 && j <= k; ++j)
		{
			L[i][j - dpt] = lower_bound(ttime[j].begin(), ttime[j].end(), tin[i]) - ttime[j].begin();
			R[i][j - dpt] = upper_bound(ttime[j].begin(), ttime[j].end(), tout[i]) - ttime[j].begin() - 1;
		}
	}
	//cout << get(2, 1, 0, sz[2] - 1, 0, sz[2] - 1).fs << endl;
	dpth[0] = -1;
	while(m--)
	{
		scanf("%d", &f);
		if(f == 1)
		{
			scanf("%d%d", &x, &y);
			int dpt = dpth[x]; int c = y, v = x, dw = dpt, up = dpt, son = 0;
			for(int i = dpt; i >= 0 && c > 0; --i)
			{
				c /= 2;
				dw = i;
			}
			c = y;
			for(int i = dpt; i <= k && c > 0; ++i)
			{
				c /= 2;
				up = i;
			}
			c = y;
			for(int i = dpt; i <= k && c > 0; ++i)
			{
				upd(i, 1, 0, sz[i] - 1, L[x][i - dpt], R[x][i - dpt], -c);
				c /= 2;
			}
			c = y / 2; son = x; v = pr[x];
			for(int i = dpt - 1; i >= 0 && c > 0; --i)
			{
				int cc = c;
				upd(i, 1, 0, sz[i] - 1, L[v][0], R[v][0], -c);
				cc /= 2;
				for(int j = i + 1; j <= k && cc > 0; ++j)
				{
					if(L[son][j - 1 - i] - 1 >= L[v][j - i])
						upd(j, 1, 0, sz[j] - 1, L[v][j - i], L[son][j - 1 - i] - 1, -cc);
					if(R[son][j - 1 - i] + 1 <= R[v][j - i])
						upd(j, 1, 0, sz[j] - 1, R[son][j - 1 - i] + 1, R[v][j - i], -cc);
					cc /= 2;
				}
				son = v; v = pr[v]; c /= 2;
			}
			//cout << sz[2] << endl;
			//cout << get(2, 1, 0, sz[2] - 1, 2, 4).fs << endl;
			//cout << levels[2][get(2, 1, 0, sz[2] - 1, L[2][1], R[2][1]).sd] << endl;
			for(int i = dw; i <= up; ++i)
			{
				bool flag = true;
				while(flag)
				{
					flag = false;
					pair < long long, int > f = get(i, 1, 0, sz[i] - 1, 0, sz[i] - 1);
					if(f.fs <= 0)
					{
						upd(i, 1, 0, sz[i] - 1, f.sd, f.sd, (long long)1e15), flag = true;
						bad[levels[i][f.sd]] = 1; uu[pt++] = levels[i][f.sd];
						//if(dbg) 
						//	cout << levels[i][f.sd] << endl;
						if(pt % Block == 0)
							use(1, 0), pt = 0;
					}
				}
			}
		}
		else
		{
			scanf("%d", &x);
			int ans = cnt[x];
			for(int i = 0; i < pt; ++i)
				if(par(x, uu[i]))
					++ans;
			printf("%d\n", ans);
		}
	}
}