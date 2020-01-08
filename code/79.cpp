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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode* root) {
    return root->left == NULL && root->right == NULL;
}

int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
class Solution {
public:
    int n, m;
    vector<vector<bool> > vis;
    bool dfs(vector<vector<char>>& board, string& word, int cur, int x, int y){
        if (cur == word.length()) return true;
        for (int i = 0; i < 4; ++i){
            int cx = x + dx[i], cy = y + dy[i];
            if (cx < 0 || cx >= n || cy < 0 || cy >= m || vis[cx][cy] || board[cx][cy] != word[cur]) continue;
            vis[cx][cy] = true;
            if (dfs(board, word, cur + 1, cx, cy)) return true;
            vis[cx][cy] = false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        if (word.empty()) return true;
        n = board.size(), m = board[0].size();
        vis = vector<vector<bool> >(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (board[i][j] == word[0]){
                    vis[i][j] = true;
                    if (dfs(board, word, 1, i, j)) return true;
                    vis[i][j] = false;
                }
        return false;
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
