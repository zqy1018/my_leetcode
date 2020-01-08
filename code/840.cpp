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
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n - 2; ++i){
            for (int j = 0; j < m - 2; ++j){
                do{
                    int a = 0;
                    for (int k = 0; k < 9; ++k)
                        a |= (1 << grid[i + k / 3][j + k % 3]);
                    if(a != 1022) break;
                    if(grid[i][j] + grid[i][j + 1] + grid[i][j + 2] != 15) break;
                    if(grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2] != 15) break;
                    if(grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2] != 15) break;
                    if(grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2] != 15) break;
                    if(grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] != 15) break;
                    if(grid[i][j] + grid[i + 1][j] + grid[i + 2][j] != 15) break;
                    if(grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != 15) break;
                    if(grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] != 15) break;
                    ans++;
                }while(0);
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
