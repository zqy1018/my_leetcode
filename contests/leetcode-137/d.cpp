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
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int> > f(n, vector<int>(15005, 0));
        f[0][0] = true;
        for (int i = 0; i < n; ++i){
            for (int j = n - 1; j >= 1; --j)
                for (int k = 15000; k >= stones[i]; --k){
                    f[j][k] |= f[j - 1][k - stones[i]];
                }
        }
        int sum = 0;
        for (int i: stones)
            sum += i;
        int ans = 30000;
        for (int t = 1; t <= n - 1; ++t)
            for (int i = 0; i <= 15000; ++i)
                if(f[t][i] && i >= sum - i)
                    ans = min(ans, 2 * i - sum);
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
