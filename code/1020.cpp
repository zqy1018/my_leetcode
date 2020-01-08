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

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
class BFS{
public:
    vector<vector<bool>> vis;
    queue<int> qx, qy;
    void bfs(int n, int m){
        vis = vector<vector<bool>>(n, vector<bool>(m, false));
        while (!qx.empty()){
            int cx = qx.front(), cy = qy.front();
            qx.pop(), qy.pop();
            for (int i = 0; i < 4; ++i){
                int ex = cx + dx[i], ey = cy + dy[i];
                if (ex < 0 || ex >= n || ey < 0 || ey >= m)
                    continue;
                // to do ..
            }
        }
    }
};
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
class Solution {
public:
    vector<vector<bool>> vis;
    queue<int> qx, qy;
    int numEnclaves(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m, false));
        for (int i = 0; i < n - 1; ++i) 
            if (A[i][0] == 1) vis[i][0] = true, qx.push(i), qy.push(0);
        for (int i = 0; i < m - 1; ++i) 
            if (A[n - 1][i] == 1) vis[n - 1][i] = true, qx.push(n - 1), qy.push(i);
        for (int i = 1; i < n; ++i) 
            if (A[i][m - 1] == 1) vis[i][m - 1] = true, qx.push(i), qy.push(m - 1);
        for (int i = 1; i < m; ++i) 
            if (A[0][i] == 1) vis[0][i] = true, qx.push(0), qy.push(i);
        while (!qx.empty()){
            int cx = qx.front(), cy = qy.front();
            qx.pop(), qy.pop();
            for (int i = 0; i < 4; ++i){
                int ex = cx + dx[i], ey = cy + dy[i];
                if (ex < 0 || ex >= n || ey < 0 || ey >= m)
                    continue;
                if (vis[ex][ey] || A[ex][ey] == 0) continue;
                vis[ex][ey] = true, qx.push(ex), qy.push(ey);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) 
                if (!vis[i][j]) ans += A[i][j] == 1;
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
