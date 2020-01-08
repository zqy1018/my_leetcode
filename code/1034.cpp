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

int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
class Solution {
public:
    queue<int> qx, qy;
    vector<vector<bool>> vis;
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int cl = grid[r0][c0];
        int n = grid.size(), m = grid[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m, false));
        vis[r0][c0] = true, qx.push(r0), qy.push(c0);
        while (!qx.empty()){
            int cx = qx.front(), cy = qy.front();
            qx.pop(), qy.pop();
            for (int i = 0; i < 4; ++i){
                int ex = cx + dx[i], ey = cy + dy[i];
                if (ex < 0 || ex >= n || ey < 0 || ey >= m)
                    continue;
                if (vis[ex][ey] || grid[ex][ey] != cl) continue;
                vis[ex][ey] = true, qx.push(ex), qy.push(ey);
            }
        }
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j){
                if (!vis[i][j]) continue;
                for (int d = 0; d < 4; ++d){
                    int ex = i + dx[d], ey = j + dy[d];
                    if (ex < 0 || ex >= n || ey < 0 || ey >= m || !vis[ex][ey]){
                        grid[i][j] = color;
                        break;
                    }
                }
            }
        return grid;
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
