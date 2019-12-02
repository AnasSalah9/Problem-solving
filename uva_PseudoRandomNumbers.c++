#include <bits/stdc++.h>
#include <stdio.h>
# define M_PI  3.14159265358979323846
using namespace std;

typedef long long ll;
const int N = 1e3 + 9, M = 9e2 + 9, OO = 0x3f3f3f3f;
const double EPS = 0.00000000001;

int z, i, m, l;

vector<int> randoms;

bool exists(int x){
	for(int v : randoms) if(x == v) return 1;
	return 0;
}

int cycleSize(){
	while(!exists((z*l+i)%m)){
		randoms.push_back((z*l+i)%m);
		l = (z*l+i)%m;
	}
	return randoms.size();
}

int main(){
	//freopen ("i.in","r",stdin);
	//freopen ("no.out","w",stdout);

	int tc = 1;
	while(scanf("%d%d%d%d", &z, &i, &m, &l), z || i || m || l)
		printf("Case %d: %d\n", tc++, cycleSize()), randoms.clear();

	return 0;
}
