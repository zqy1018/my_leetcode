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
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> dis(n, vector<int>(m, 0));
        queue<int> qx, qy;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (grid[i][j] == 1)
                    qx.push(i), qy.push(j), vis[i][j] = true;
            }
        }
        if (qx.size() == n * m) return -1;
        if (qx.empty()) return -1;
        while (!qx.empty()){
            int x = qx.front(), y = qy.front();
            qx.pop(), qy.pop();
            for (int i = 0; i < 4; ++i){
                int cx = x + dx[i], cy = y + dy[i];
                if(cx < 0 || cy < 0 || cx >= n || cy >= m) continue;
                if(vis[cx][cy] || grid[cx][cy] == 1) continue;
                vis[cx][cy] = true;
                dis[cx][cy] = dis[x][y] + 1;
                qx.push(cx), qy.push(cy);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j)
                ans = max(ans, dis[i][j]);
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
