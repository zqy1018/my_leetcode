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

int st[45][45][85];
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        if (k >= n + m - 3) return n + m - 2;
        queue<int> qx, qy, qk;
        memset(st, 0x3f, sizeof(st));
        st[0][0][0] = 0;
        qx.push(0), qy.push(0), qk.push(0);
        int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
        while (!qx.empty()){
            int cx = qx.front(), cy = qy.front(), ck = qk.front();
            qx.pop(), qy.pop(), qk.pop();
            for (int i = 0; i < 4; ++i){
                int ex = cx + dx[i], ey = cy + dy[i];
                if (ex < 0 || ey < 0 || ex >= n || ey >= m) 
                    continue;
                if (grid[ex][ey]){
                    if (ck == k) continue;
                    if (st[ex][ey][ck + 1] <= st[cx][cy][ck] + 1) continue;
                    st[ex][ey][ck + 1] = st[cx][cy][ck] + 1;
                    qx.push(ex), qy.push(ey), qk.push(ck + 1);
                }else {
                    if (st[ex][ey][ck] <= st[cx][cy][ck] + 1) continue;
                    st[ex][ey][ck] = st[cx][cy][ck] + 1;
                    qx.push(ex), qy.push(ey), qk.push(ck);
                }
            }
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i <= k; ++i)
            ans = min(ans, st[n - 1][m - 1][i]);
        if (ans >= 0x3f3f3f3f) return -1;
        return ans;
    }
};
Solution sol;
void init(){
    vector<vector<int>> grid{{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
    cout << sol.shortestPath(grid, 1);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
