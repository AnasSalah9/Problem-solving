#include <bits/stdc++.h>
#include <stdio.h>
# define M_PI  3.14159265358979323846
using namespace std;

typedef long long ll;
const int N = 1e3 + 9, M = 9e2 + 9, OO = 0x3f3f3f3f;
const double EPS = 0.00000000001;

int n;
int digits[]= {1, 4, 5, 9, 10, 40, 50, 90, 100};
char symbol[][10] = {"i", "iv", "v", "ix", "x", "xl", "l", "xc", "c"};
int cnt[5];

void changeCnt(char* s){
	for(int i = 0 ; s[i] ; ++i){
		if(s[i] == 'i') ++cnt[0];
		else if(s[i] == 'v') ++cnt[1];
		else if(s[i] == 'x') ++cnt[2];
		else if(s[i] == 'l') ++cnt[3];
		else if(s[i] == 'c') ++cnt[4];
	}
}

void print(int x){
	 printf("%d: ", x);
	for(int i = 1 ; i <= x ; ++i){
		int y = i;
		while(y){
			int idx = lower_bound(digits, digits+9, y)-digits;
			if(digits[idx] == y)  changeCnt(symbol[idx]), y -= digits[idx];
			else changeCnt(symbol[idx-1]), y -= digits[idx-1];
		}
	}
	printf("%d i, %d v, %d x, %d l, %d c\n", cnt[0], cnt[1], cnt[2], cnt[3], cnt[4]);
	for(int i = 0 ; i < 5 ; ++i) cnt[i] = 0;
}


int main(){
	//freopen ("i.in","r",stdin);
	//freopen ("no.out","w",stdout);

	while(scanf("%d", &n), n) print(n);

	return 0;
}
