/*
basic idea
there are n/2 nums till n which have floor(N/i) as 1
like this count group of nums which have same floor(N/i)

let x = N
number of nums with 1 as floor(N/i) = x - (N/2) => N-N/2   = N/2
x = N/2;
number of nums with 2 as floor(N/i) = x - (N/3) => N/2-N/3 = N/6
x = N/3
number of nums with 3 as floor(N/i) = x - (N/4) => N/3-N/4 = N/12
x = N/4
number of nums with 4 as floor(N/i) = x - (N/5) => N/4-N/5 = N/20
.
.
.
.
.
x = N/sqrt(N)
number of nums with ... as floor(N/i) = x - ...


// sum of fourth powers
a(n) = n*(1+n)*(1+2*n)*(-1+3*n+3*n^2)/30

100000000 100000

https://oeis.org/A064604

*/

#include <bits/stdc++.h>
using namespace std;

#define LL long long

LL compute(LL x, LL m){
	LL ret = (  );
}

(x*(1+x)*(1+2*x)*(-1+3*x+3*pow(x,2))/30)

int main()
{
	LL n;
	cin >> n >> m;
	LL imax = n;
	LL imin = n/2;
	LL cr = 2;
	while(imax - imin > 5){

	}

	return 0;
}