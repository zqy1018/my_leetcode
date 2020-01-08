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
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int> > f(2, vector<int>(n + 1, 0x3f3f3f3f));
        f[0][0] = 0;
        for (int i = 0; i < n; ++i){
            int B = (i + 1) & 1, B_ = (i & 1);
            fill(f[B].begin(), f[B].end(), 0x3f3f3f3f);
            for (int j = 0; j < i + 1; ++j)
                f[B][j] = min(f[B_][j] + triangle[i][j], f[B][j]), 
                f[B][j + 1] = min(f[B_][j] + triangle[i][j], f[B][j + 1]);
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i){
            ans = min(ans, f[n & 1][i]);
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
