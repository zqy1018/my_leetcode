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

bool vis[105][105];
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
        int n = grid.size(), m = grid[0].size();
        queue<int> qx, qy;
        int ans = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j){
                if (!vis[i][j] && grid[i][j] == 0){
                    vis[i][j] = true, qx.push(i), qy.push(j);
                    bool flag = true;
                    while (!qx.empty()){
                        int cx = qx.front(), cy = qy.front();
                        qx.pop(), qy.pop();
                        for (int t = 0; t < 4; ++t){
                            int ex = cx + dx[t], ey = cy + dy[t];
                            if (ex < 0 || ex >= n || ey < 0 || ey >= m) {
                                flag = false;
                                continue;
                            }
                            if (vis[ex][ey] || grid[ex][ey] != 0)   
                                continue;
                            qx.push(ex), qy.push(ey), vis[ex][ey] = true;
                        }
                    }
                    if (flag) ++ans;
                }
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
