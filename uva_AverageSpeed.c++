#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 9, M = 3e5 + 9, OO = 0x3f3f3f3f;
const double EPS = 0.0000000001, PI = 3.14159265358979;
const int mod = 1000003;

int prvTime[3], curTime[3];
double prvSpeed, curSpeed, accDist;
char input[50], sep;


double calculateDistance(){ //from (curTime-prvTime)*prvSpeed
	double t1 = prvTime[0]+(prvTime[1]/60.0)+(prvTime[2]/3600.0);
	double t2 = curTime[0]+(curTime[1]/60.0)+(curTime[2]/3600.0);
	return (t2-t1)*prvSpeed;
}

int main(){
	// freopen("i.in", "rt", stdin);
	// freopen("o.out", "wt", stdout);

	while(scanf("%[^\n]%*c", input) != EOF){
		int sz = strlen(input);
		if(sz > 8){ // speed update;
			sscanf(input, "%d %c %d %c %d %lf", curTime, &sep, curTime+1 , &sep, curTime+2 , &curSpeed);
			accDist += calculateDistance();
			prvSpeed = curSpeed;
			prvTime[0] = curTime[0], prvTime[1] = curTime[1], prvTime[2] = curTime[2];
		}
		else{  // query
			sscanf(input, "%d %c %d %c %c %d", curTime, &sep, curTime+1 , &sep, &sep, curTime+2);
			accDist += calculateDistance();
			printf("%s %.2lf km\n", input, accDist);
			prvTime[0] = curTime[0], prvTime[1] = curTime[1], prvTime[2] = curTime[2];
		}
	}


	return 0;
}
