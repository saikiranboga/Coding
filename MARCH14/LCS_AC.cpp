/*
USER: freeman92

similar problem to that of "http://www.spoj.com/problems/LCS/"

below code is a modified version of the submission to the above problem by unknown
user taken from the src:"http://code.ohloh.net/file?fid=Vo8O_0RS_kVE_qimdGeEYqVB1eg&cid=Ywm3y8tvb_E&s=&fp=399846&mp&projSelected=true#L0"

And there is no infringement of the codechef's code of conduct mentioned at the 
link: "http://discuss.codechef.com/questions/18662/does-codechef-have-any-code-of-conduct"

Refer to this point: 
Taking help or using a third party code is not bad. Passing it off as your own is.
If you are taking your code from some other source, 
it is expected that you give the due attribution to the source in your code. It is kind of mandatory.

*/
#include <stdio.h>
#include <string.h>

const int MAXLEN = 250052;
const int K = 26;

struct state {
	int length, link, next[K];
} st[MAXLEN*2-1];

int sz, last;
char A[MAXLEN], B[MAXLEN];

void init() {
	st[0].link = -1;
	memset(st[0].next, -1, sizeof st[0].next);
	sz++;
}

void extend(char c) {
	int nlast = sz++, p, q, clone;
	st[nlast].length = st[last].length + 1;
	memset(st[nlast].next, -1, sizeof st[nlast].next);
	for(p=last; p!=-1 && st[p].next[c]==-1; p=st[p].link) st[p].next[c] = nlast;
	if(p == -1) st[nlast].link = 0;
	else{
		q = st[p].next[c];
		if(st[p].length + 1 == st[q].length) st[nlast].link = q;
		else{
			clone = sz++;
			st[clone].length = st[p].length + 1;
			memcpy(st[clone].next, st[q].next, sizeof st[clone].next);
			st[clone].link = st[q].link;
			for(; p!=-1 && st[p].next[c]==q; p=st[p].link) st[p].next[c] = clone;
			st[q].link = st[nlast].link = clone;
		}
	}
	last = nlast;
}
int bp=-1;
int lcs(char *a, char *b) {
	int i, p, l, best, bestpos;
	init();
	for(i=0; a[i]; i++) extend (a[i]-'a');
	p = 0, l = 0, best = 0, bestpos = 0;
	for(i=0; b[i]; i++) {
		if(st[p].next[b[i]-'a'] == -1) {
			for(; p!=-1 && st[p].next[b[i]-'a'] == -1; p=st[p].link);
			if (p == -1) {
				p = l = 0;
				continue;
			}
			l = st[p].length;
		}
		p = st[p].next[b[i]-'a']; l++;
		if(l > best) best = l, bestpos = i;
	}
	bp = bestpos;
	return best;
}

int main() {
	gets(A);
	gets(B);

	int ans = lcs(A,B);
	if(ans==0){
		printf("0\n");
	}
	else{
		for(int i=bp-ans+1;i<=bp;i++){
			printf("%c",B[i]);
		}
		printf("\n");
		printf("%d\n", ans);
	}
	return 0;
}
