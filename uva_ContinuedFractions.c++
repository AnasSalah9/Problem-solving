#include <bits/stdc++.h>
#include <stdio.h>
# define M_PI  3.14159265358979323846
using namespace std;

typedef long long ll;
const int N = 1e5, M = 3e5 + 9, OO = 0x3f3f3f3f;
const double EPS = 0.00000000001;
const int mod = 1000000007;

int num, den;
vector<int> ans;

int main(){
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	while(scanf("%d%d", &num, &den) != EOF){
		ans.clear();
		while(den != 0){
			int q = num/den;
			ans.push_back(q);
			int tmp = num;
			num = den;
			den = tmp-q*den;
		}
		printf("[%d;", ans[0]);
		for(int i = 1 ; i < (int)ans.size() ; ++i) printf("%d%s", ans[i], ( i == (int)ans.size()-1 ? "" : ","));
		puts("]");
	}

	return 0;
}
