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
class Solution {
public:
    int poww(int a, int b, int c){
        int res = 1;
        while(b){
            if(b & 1) res = res * a % c;
            a = a * a % c, b >>= 1;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        a %= 1337;
        int n = b.size();
        int flag = 0, bb = 0;
        for (int i = 0; i < n; ++i){
            bb = bb * 10 + b[i];
            if(bb >= 1140) flag = 1, bb %= 1140;
        }
        int res = poww(a, bb, 1337);
        if(flag) res = res * poww(a, 1140, 1337) % 1337;
        return res;
    }
};
Solution sol;
void init(){
    
}
void solve(){
	// sol.convert();
}
int main(){
	init();
	solve();
	return 0;
}
