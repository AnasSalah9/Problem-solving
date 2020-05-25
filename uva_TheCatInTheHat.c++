#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 9, M = 3e5 + 9, OO = 0x3f3f3f3f;
const double EPS = 0.0000000001;
const ll mod = 1e18+2;

ll h, m, n, l;

ll fpow(ll base, ll exp){
	if(exp == 0) return 1;
	ll sub = fpow(base, exp/2);
	return sub*sub*(exp&1 ? base : 1);
}

bool ok(ll x){
	return fpow(x, l) <= m;
}

ll binarySearch(ll high){
	ll lo = 1, hi = high+1, med;
	while(lo < hi){
		med = ((lo+hi)+1)/2;
		if(ok(med)) lo = med;
		else hi = med-1;
	}
	return lo;
}

ll notWorking(){
	ll cnt = 0;
	for(int i = 0 ; i < l ; ++i) cnt += fpow(n, i);
	return cnt;
}

ll heightsSum(){
	ll cnt = 0;
	for(int i = 0 ; i <= l ; ++i) cnt += (h*fpow(n, i))/fpow(n+1, i);
	return cnt;
}

int main(){
	// freopen("i.in", "rt", stdin);
	// freopen("o.out", "wt", stdout);

	while(scanf("%lld%lld", &h, &m), m){
		if(h == 1 && m == 1) n = 1, l = 0;
		else{
				for(l = 1 ; l < 64 ; ++l){
				n = binarySearch(pow(10, 18/(double)l));
				if(fpow(n, l) == m && fpow(n+1, l) == h) break;
				}
		}
		printf("%lld %lld\n", notWorking(), heightsSum());
	}


	return 0;
}
