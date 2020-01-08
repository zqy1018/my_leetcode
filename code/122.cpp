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
        vector<int> f(n, 0);
        int pst1 = -prices[0], ans = 0;
        for (int i = 1; i < n; ++i){
            int tmp = prices[i] + pst1;
            f[i] = max(tmp, f[i - 1]);
            ans = max(ans, tmp);
            pst1 = max(pst1, f[i - 1] - prices[i]);
        }
        return ans;
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
