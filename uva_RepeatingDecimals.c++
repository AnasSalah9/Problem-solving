#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 9, M = 3e5 + 9, OO = 0x3f3f3f3f;
const double EPS = 0.0000000001;
const ll mod = 1e18+2;

int num, den, num2, cycStart;
vector<int> front, back;
vector<pair<int, int>> trace;


void fillFront(){
	if(num < den) front.push_back(0);
	else while(num >= den) front.push_back(num/den), num -= (num/den)*den;
}

bool existInTrace(int x){
	for(auto v : trace) if(v.first == x) return 1;
	return 0;
}

void fillBack(){
	while(num){
		if(num < den) num *= 10;
		if(existInTrace(num)) break;
		trace.push_back({num, (int)back.size()});
		back.push_back(num/den);
		num -= (num/den)*den;
	}
	if(!num && !((int)back.size())) back.push_back(0), cycStart = 0;
	else if(!num) back.push_back(0), cycStart = (int)back.size()-1;
	else for(auto v : trace) if(v.first == num) cycStart = v.second;
}


int main(){
	//freopen("i.in", "rt", stdin);
	//freopen("o.out", "wt", stdout);

	while(scanf("%d%d", &num, &den) != EOF){
		num2 = num;
		fillFront();
		fillBack();
		printf("%d/%d = ", num2, den);
		for(auto v : front) printf("%d", v);
		printf(".");
		if((int)back.size() > 50){
			for(int i = 0 ; i < 50 ; ++i){
				if(i == cycStart) printf("(");
				printf("%d", back[i]);
			}
			printf("...");
		}
		else
			for(int i = 0 ; i < (int)back.size() ; ++i){
				if(i == cycStart) printf("(");
				printf("%d", back[i]);
			}
		printf(")\n");
		printf("   %d = number of digits in repeating cycle\n\n", (int)back.size()-cycStart);
		front.clear(), back.clear(), trace.clear();
	}


	return 0;
}
