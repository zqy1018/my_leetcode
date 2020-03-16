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

const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
class Solution {
public:
    int n, m, dis[105][105], tmp[105][105];
    bool vis[105][105], unable[105][105];
    queue<int> qx, qy;
    void bfs(int x, int y, vector<vector<int>>& grid){
        memset(vis, 0, sizeof(vis));
        memset(tmp, 0, sizeof(tmp));
        qx.push(x), qy.push(y);
        vis[x][y] = true;
        tmp[x][y] = 0;
        while (!qx.empty()){
            x = qx.front(), y = qy.front();
            qx.pop(), qy.pop();
            for (int i = 0; i < 4; ++i){
                int cx = x + dx[i], cy = y + dy[i];
                if (cx < 0 || cy < 0 || cx >= n || cy >= m) 
                    continue;
                if (!vis[cx][cy] && !grid[cx][cy])
                    tmp[cx][cy] = tmp[x][y] + 1, 
                    vis[cx][cy] = true, 
                    qx.push(cx), qy.push(cy);
            }
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (!grid[i][j]){
                    if (!vis[i][j]) unable[i][j] = true;    // 屏蔽
                    else dis[i][j] += tmp[i][j];
                }
    }
    int shortestDistance(vector<vector<int>>& grid) {
        n = grid.size();
        if (!n) return 0;
        m = grid[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j]){
                    bfs(i, j, grid);
                }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (!unable[i][j] && !grid[i][j])
                    ans = min(ans, dis[i][j]);
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
