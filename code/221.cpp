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
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(!n) return 0;
        int m = matrix[0].size(), ans = 0;
        vector<vector<int> > f(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if(matrix[i][j] == '0') continue;
                int res = max(n, m);
                if(i && j) {
                    res = min(res, f[i - 1][j - 1]);
                    res = min(res, f[i][j - 1]);
                    res = min(res, f[i - 1][j]);
                }else res = 0;
                f[i][j] = 1 + res;
                ans = max(ans, f[i][j] * f[i][j]);
            }
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
