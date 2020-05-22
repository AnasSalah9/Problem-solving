#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 9, M = 3e5 + 9, OO = 0x3f3f3f3f;
const double EPS = 0.0000000001;
const int mod = 1000003;


ll Cn[30], n;

void fillCn(){
	Cn[0] = 1;
	for(int i = 0 ; i < 29 ; ++i) Cn[i+1] = (2*(2*i+1)*Cn[i])/(i+2);
}


int main(){
	// freopen("i.in", "rt", stdin);
	// freopen("o.out", "wt", stdout);

	fillCn();
	Cn[0] = 0;
	while(scanf("%lld", &n) != EOF)
		for(int i = 0 ; i < 30 ; ++i) if(Cn[i] == n) printf("%d\n", i);


	return 0;
}
