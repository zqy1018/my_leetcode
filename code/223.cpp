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
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int A1 = (C - A) * (D - B), A2 = (G - E) * (H - F);
		int A3 = (min(C, G) > max(A, E) ? min(C, G) - max(A, E): 0) * 
			(min(D, H) > max(B, F) ? min(D, H) - max(B, F): 0);
		return A1 - A3 + A2;
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
