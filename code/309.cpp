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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        if(n <= 2) return max(0, prices[1] - prices[0]);
        int bef = max(-prices[0], -prices[1]);
        int f0 = 0, f1 = max(0, prices[1] - prices[0]), f2 = 0;
        for (int i = 2; i < n; ++i) {
            f2 = max(f1, bef + prices[i]);
            bef = max(bef, f0 - prices[i]);
            f0 = f1, f1 = f2;
        }
        return f1;
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
