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
    int n, m;
    void dfs(int x, int y, char to, vector<vector<char>>& board, int *dx, int *dy){
        for (int i = 0; i < 4; ++i){
            int cx = x + dx[i], cy = y + dy[i];
            if(cx < 0 || cy < 0 || cx >= n || cy >= m) continue;
            if(board[cx][cy] == 'O')
                board[cx][cy] = to, dfs(cx, cy, to, board, dx, dy);
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        if(!n) return ;
        m = board[0].size();
        int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
        for (int i = 0; i < n; ++i){
            if(board[i][0] == 'O')
                dfs(i, 0, 'C', board, dx, dy);
            if(board[i][m - 1] == 'O')
                dfs(i, m - 1, 'C', board, dx, dy);
        }
        for (int i = 1; i < m - 1; ++i){
            if(board[0][i] == 'O')
                dfs(0, i, 'C', board, dx, dy);
            if(board[n - 1][i] == 'O')
                dfs(n - 1, i, 'C', board, dx, dy);
        }
        for (int i = 1; i < n - 1; ++i)
            for (int j = 1; j < m - 1; ++j)
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) 
                if(board[i][j] == 'C')
                    board[i][j] = 'O';
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
