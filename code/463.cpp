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
    int islandPerimeter(vector<vector<int>>& grid) {
        int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
        int n = grid.size();
        if(!n) return 0;
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if(grid[i][j] == 1){
                    for (int e = 0; e < 4; ++e){
                        int cx = i + dx[e], cy = j + dy[e];
                        if(cx < 0 || cy < 0 || cx >= n || cy >= m || grid[cx][cy] == 0)
                            ans++;
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
