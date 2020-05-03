#include <bits/stdc++.h>
#include <stdio.h>
# define M_PI  3.14159265358979323846
using namespace std;

typedef long long ll;
const int N = 1e5, M = 3e5 + 9, OO = 0x3f3f3f3f;
const double EPS = 0.00000000001;
const int mod = 1000000007;


typedef pair<pair<int, int>, pair<int, int>> pp;
vector<pair<pair<int, int>, pair<int, int>>> ans;

int CubeRoot(int x){
	for(int i = 2 ; i*i*i <= x ; ++i) if(i*i*i == x) return i;
	return -1;
}

bool samePair(pp l, pp r){
	int a = l.first.first;
	int b = l.first.second;
	int c = l.second.first;
	int d = l.second.second;
	int w = r.first.first;
	int x = r.first.second;
	int y = r.second.first;
	int z = r.second.second;
	bool c1 = (a == w);
	bool c2 = (b == x || b == y || b == z);
	bool c3 = (c == x || c == y || c == z);
	bool c4 = (d == x || d == y || d == z);
	if(c1 && c2 && c3 && c4) return 1;
	return 0;
}

void deleteRepeated(){
	for(int i = 0 ; i < (int)ans.size() ; ++i){
		if(~ans[i].first.first)
			for(int j = i+1 ; j < (int)ans.size() ; ++j)
				if(~ans[j].first.first && samePair(ans[i], ans[j])) ans[j].first.first = -1;
	}
}


int main(){
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);


	for(int a = 2 ; a <= 200 ; ++a)
		for(int b = 2 ; b <= 200 ; ++b)
			for(int c = 2 ; c <= 200 ; ++c){
				int d = a*a*a - b*b*b - c*c*c;
				if(d > 0 && ~(d = CubeRoot(d))) ans.push_back({{a, b}, {c, d}});
			}
	deleteRepeated();
	for(pp v : ans)
		if(~v.first.first)
			printf("Cube = %d, Triple = (%d,%d,%d)\n", v.first.first, v.first.second,
								v.second.first, v.second.second);

	return 0;
}
