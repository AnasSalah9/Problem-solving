#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 9, M = 3e5 + 9, OO = 0x3f3f3f3f;
const double EPS = 0.0000000001, PI = 3.14159265358979;
const int mod = 1000003;

ll n, k;

ll extra(){
	ll q = n/k, r = n%k, cnt = 0;
	while(q){
		cnt += q;
		q += r;
		r = q%k;
		q = q / k;
	}
	return cnt;
}

int main(){
	// freopen("i.in", "rt", stdin);
	// freopen("o.out", "wt", stdout);

	while(scanf("%lld%lld", &n, &k) != EOF) printf("%lld\n", n+extra());

	return 0;
}
