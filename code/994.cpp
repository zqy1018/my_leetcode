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
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<int> x, y;
        int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0}, lft = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j){
                if(grid[i][j] == 2) x.push(i), y.push(j);
                else if (grid[i][j] == 1) lft++;
            }
        int ans = 0;
        for (; lft; ans++){
            int siz = x.size();
            if(!siz) break;
            while(siz--){
                int cx = x.front(), cy = y.front();
                x.pop(), y.pop();
                for (int i = 0; i < 4; ++i){
                    int ex = cx + dx[i], ey = cy + dy[i];
                    if(ex < 0 || ex >= n || ey < 0 || ey >= m) continue;
                    if(grid[ex][ey] == 1) {
                        grid[ex][ey] = 2;
                        lft--;
                        x.push(ex), y.push(ey);
                    }
                }
            }
        }
        if(lft) return -1;
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
