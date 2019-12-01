#include <bits/stdc++.h>
#include <stdio.h>
# define M_PI  3.14159265358979323846
using namespace std;

typedef long long ll;
const int N = 1e3 + 9, M = 9e2 + 9, OO = 0x3f3f3f3f;
const double EPS = 0.00000000001;


int n;

int y1(int x){
	double v = 0.5 - x + sqrt(0.25 + x*(pow(10, n/2)-1));
	int i = v;
	if(abs(v-i) <= 1e-9) return i;
	return -OO;
}

int y2(int x){
	double v = 0.5 - x - sqrt(0.25 + x*(pow(10, n/2)-1));
	int i = v;
	if(abs(v-i) <= 1e-9 && i > -1) return i;
	return -OO;
}

int countDigits(int x){
	int i = 0;
	while(x) x /= 10, ++i;
	return max(1, i);
}

void print(int v1, int v2){
	if(v2 != -OO){
		int c2 = countDigits(v2);
		if(c2 != n) for(int i = 0 ; i < n-c2 ; ++i) printf("0");
		printf("%d\n", v2);
	}
	if(v1 != -OO){
		int c1 = countDigits(v1);
		if(c1 != n) for(int i = 0 ; i < n-c1 ; ++i) printf("0");
		printf("%d\n", v1);
	}
}

int main(){
	//freopen ("i.in","r",stdin);
	//freopen ("no.out","w",stdout);

	while(scanf("%d", &n) != EOF){
		for(int x = 0 ; x < pow(10, n/2) ; ++x){
			int val1 = y1(x);
			if(val1 != -OO) val1 = x*pow(10, n/2) + val1;
			int val2 = y2(x);
			if(val2 != -OO) val2 = x*pow(10, n/2) + val2;
			print(val1, val2);
		}
	}

	return 0;
}
