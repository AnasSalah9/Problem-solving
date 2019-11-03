#include <bits/stdc++.h>
# define M_PI  3.14159265358979323846
using namespace std;

typedef unsigned long long ll;
const int N = 2e2 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const double EPS = 0.00000000001;

int n, x;
ll mem[N][N], a, b, g;


ll fpow(ll base, ll exp){
	if(exp == 0) return 1;
	ll sub = fpow(base, exp/2);
	return sub*sub*(exp&1?base:1);
}

ll gcd(ll a, ll b){
	if(!b) return a;
	return gcd(b, a%b);
}

ll count(int i = 0, int s = 0){
	if(i == n) return (s >= x);
	ll& ret = mem[i][s];
	if(~ret) return ret;
	ll sum = 0;
	for(int j = 1 ; j <= 6 ; ++j) sum += count(i+1, s+j);
	return ret = sum;
}


int main(){
	//freopen ("i.in","r",stdin);
	//freopen ("o.out","w",stdout);


	while(scanf("%d%d", &n, &x), n){
			memset(mem, -1, sizeof mem);
			a = count();
			b = fpow(6, n);
			g = gcd(a, b);
			a /= g;
			b /= g;
			if(a == 0) printf("0\n");
			else if(a == b) printf("1\n");
			else printf("%lld/%lld\n", a, b);
	}
	
	return 0;
}
