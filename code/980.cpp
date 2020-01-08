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

int n, m, ans, tot;
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
bool vis[25][26];
class Solution {
public:
    void dfs(int cx, int cy, vector<vector<int>>& grid){
        if (grid[cx][cy] == 2){
            if (tot == n * m) ++ans;
            return ;
        }
        for (int i = 0; i < 4; ++i) {
            int ex = cx + dx[i], ey = cy + dy[i];
            if (ex < 0 || ey < 0 || ex >= n || ey >= m)
                continue;
            if (grid[ex][ey] < 0 || vis[ex][ey])
                continue;
            vis[ex][ey] = true, ++tot;
            dfs(ex, ey, grid);
            vis[ex][ey] = false, --tot;
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        memset(vis, 0, sizeof(vis));
        tot = ans = 0;
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == -1)   
                    ++tot;
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 1){
                    ++tot, vis[i][j] = true, dfs(i, j, grid);
                    return ans;
                }
        return 0;
    }
};
Solution sol;
void init(){
    vector<vector<int>> vec(4, vector<int>(5, 0));
    vec[0][0] = 1, vec[3][4] = 2;
    cout << sol.uniquePathsIII(vec);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
