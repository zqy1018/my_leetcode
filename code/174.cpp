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
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        if(!n) return 1;
        int m = dungeon[0].size();
        int l = 1, r = 0, cur = 0;
        for (int i = 0; i < m; ++i)
            cur += dungeon[0][i], r = min(r, cur);
        for (int i = 1; i < n; ++i)
            cur += dungeon[i][m - 1], r = min(r, cur);
        r = -r + 1;
        while(r > l){
            int mid = (l + r) >> 1;
            vector<vector<int> > f(n, vector<int>(m, -1));
            f[0][0] = mid + dungeon[0][0];
            for (int i = 1; i < m; ++i)
                if(f[0][i - 1] > 0) f[0][i] = f[0][i - 1] + dungeon[0][i];
            for (int i = 1; i < n; ++i){
                if(f[i - 1][0] > 0) f[i][0] = f[i - 1][0] + dungeon[i][0];
                for (int j = 1; j < m; ++j){
                    int res = -1;
                    if(f[i - 1][j] > 0) res = max(res, f[i - 1][j]);
                    if(f[i][j - 1] > 0) res = max(res, f[i][j - 1]);
                    f[i][j] = res + dungeon[i][j];
                }
            }
            if(f[n - 1][m - 1] > 0)
                r = mid;
            else l = mid + 1;
        }
        return l;
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
