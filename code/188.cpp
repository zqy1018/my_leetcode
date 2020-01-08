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
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        vector<vector<int> > f(2, vector<int>(n, 0));
        int mini = prices[0];
        for (int i = 1; i < n; ++i){
            f[1][i] = max(prices[i] - mini, f[1][i - 1]);
            mini = min(mini, prices[i]);
        }
        int lstans = 0;
        for (int i = 2; i <= k; ++i){
            int B = i & 1, B_ = 1 - B;
            fill(f[B].begin(), f[B].end(), 0);
            int pst1 = -prices[0], curans = 0;
            for (int j = 1; j < n; ++j){
                int tmp = prices[j] + pst1;
                f[B][j] = max(tmp, f[B][j - 1]);
                curans = max(tmp, f[B][j]);
                pst1 = max(pst1, f[B_][j - 1] - prices[j]);
            }
            if(curans == lstans) return curans;
            lstans = curans;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, f[k & 1][i]);
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
