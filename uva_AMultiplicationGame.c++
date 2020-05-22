#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 9, M = 3e5 + 9, OO = 0x3f3f3f3f;
const double EPS = 0.0000000001;
const int mod = 1000003;

ll n;


map<pair<ll, bool>, bool> mem;

bool winner(ll p, bool player){
	if(p >= n) return !player;
	for(int i = 2 ; i <= 9; ++i){
		if(mem.find({p*i, !player}) == mem.end()) mem[{p*i, !player}] = winner(p*i, !player);
		if(mem[{p*i, !player}] == player) return player; // return mem[{p*i, !player}]
	}
	return mem[{p, player}] = !player;
}


int main(){
	// freopen("i.in", "rt", stdin);
	// freopen("o.out", "wt", stdout);

	while(scanf("%lld", &n) != EOF)
		(winner(1, 1) ? puts("Stan wins.") : puts("Ollie wins.")), mem.clear();


	return 0;
}
