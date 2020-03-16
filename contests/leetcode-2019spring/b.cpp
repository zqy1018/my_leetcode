#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
	int f = 1, x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
	while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	return f * x; 
}
int n;
void init(){
    n = read();
    if(N % 10 == 0){
        if(N == 0) return false;
        else return true;
    }
    for (int t = N; t; t /= 10){
        if(t % 10 == 2 || t % 10 == 3 || t % 10 == 4 || t % 10 == 5 || t % 10 == 7)
            return false;
    }
    int res = 0;
    for (int t = N; t; t /= 10){
        int dd = t % 10;
        if(dd == 6) dd = 9;
        else if(dd == 9) dd = 6;
        res = res * 10 + dd;
    }
    return res == N;
}
void solve(){
	
}
int main(){
	init();
	solve();
	return 0;
}
