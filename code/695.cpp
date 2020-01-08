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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
        int n = grid.size();
        if(!n) return 0;
        int m = grid[0].size();
        vector<vector<bool> > vis(n, vector<bool>(m, 0));
        queue<pair<int, int> > q;
        auto v = [&grid, &q, &vis, dx, dy, n, m](int x, int y){
            q.push(make_pair(x, y));
            vis[x][y] = true;
            int res = 1;
            while(!q.empty()){
                x = q.front().first, y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; ++i){
                    int cx = x + dx[i], cy = y + dy[i];
                    if(cx < 0 || cy < 0 || cx >= n || cy >= m) continue;
                    if(vis[cx][cy] || grid[cx][cy] == '0') continue;
                    vis[cx][cy] = true;
                    q.push(make_pair(cx, cy));
                    res++;
                }
            }
            return res;
        };
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if(!vis[i][j] && grid[i][j] == '1')
                    ans = max(ans, v(i, j));
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
