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
int f[105][105], g[105];
class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		f[0][0] = 1;
		int M = 1000000007, n = group.size();
		for (int i = 0; i < n; ++i){
			for (int j = G; j >= group[i]; --j){
				for (int p = max(0, P - profit[i] + 1); p <= P; ++p)
					g[j] = (g[j] + f[j - group[i]][p] >= M ? g[j] + f[j - group[i]][p] - M: g[j] + f[j - group[i]][p]);
				g[j] = (g[j] + g[j - group[i]] >= M ? g[j] + g[j - group[i]] - M: g[j] + g[j - group[i]]);
				for (int p = P; p >= profit[j]; --p)	
					f[j][p] = (f[j][p] + f[j - group[i]][p - profit[i]] >= M ?
						f[j][p] + f[j - group[i]][p - profit[i]] - M: f[j][p] + f[j - group[i]][p - profit[i]]);
			}
		}
		int ans = 0;
		for (int i = 0; i <= G; ++i)
			ans = (ans + f[i][P] >= M ? ans + f[i][P] - M: ans + f[i][P]), 
			ans = (ans + g[i] >= M ? ans + g[i] - M: ans + g[i]);
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
