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
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size(), ss = 0;
        for (int v: nums) ss += v;
        if(S < -ss || S - ss > 0) return 0;
        vector<vector<int> > f(2, vector<int>(ss + ss + 1, 0));
        f[0][ss] = 1;
        for (int i = 1; i <= n; ++i){
            int v = nums[i - 1];
            fill(f[i & 1].begin(), f[i & 1].end(), 0);
            for (int j = 0; j <= ss + ss; ++j){
                if(j - v >= 0)
                    f[i & 1][j] += f[(i & 1) ^ 1][j - v];
                if(j + v <= ss + ss)
                    f[i & 1][j] += f[(i & 1) ^ 1][j + v];
            }
        }
        return f[n & 1][S + ss];
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
