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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool vis[20][20];
int ans, dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
class Solution {
public:
    void dfs(int cx, int cy, int acc, vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        ans = max(ans, acc);
        for (int i = 0; i < 4; ++i){
            int ex = cx + dx[i] , ey = cy + dy[i];
            if (ex < 0 || ey < 0 || ex >= n || ey >= m)
                continue;
            if (!grid[ex][ey] || vis[ex][ey]) continue;
            vis[ex][ey] = true, dfs(ex, ey, acc + grid[ex][ey], grid);
            vis[ex][ey] = false;
        }
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j){
                if (!grid[i][j]) continue;
                memset(vis, 0, sizeof(vis));
                vis[i][j] = true, dfs(i, j, grid[i][j], grid);
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
