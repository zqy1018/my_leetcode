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
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> f(n + 1, vector<int>(2 * n + 1, 0x3f3f3f3f)); //初始层数，赋值
        f[0][n] = 0;
        for (int i = 0; i < n; ++i){
            for (int j = -n; j <= n; ++j){
                if(j - 1 + n >= 0)
                    f[i + 1][j + n] = min(f[i + 1][j + n], f[i][j - 1 + n] + costs[i][0]);
                if(j + 1 + n <= 2 * n)
                    f[i + 1][j + n] = min(f[i + 1][j + n], f[i][j + 1 + n] + costs[i][1]);
            }
        }
        return f[n][n];
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
