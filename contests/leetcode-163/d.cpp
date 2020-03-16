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


bool vis[25][25];
int st[25][25][5];
class Solution {
public:
    queue<int> qx, qy;
    void valid(vector<vector<char>>& grid, int bx, int by, int curx, int cury){
        memset(vis, 0, sizeof(vis));
        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
        int n = grid.size(), m = grid[0].size();
        qx.push(curx), qy.push(cury);
        vis[curx][cury] = true;
        while (!qx.empty()){
            int cx = qx.front(), cy = qy.front();
            qx.pop(), qy.pop();
            for (int i = 0; i < 4; ++i){
                int ex = cx + dx[i], ey = cy + dy[i];
                if (ex < 0 || ex >= n || ey < 0 || ey >= m)
                    continue;
                if (ex == bx && ey == by) continue;
                if (vis[ex][ey] || grid[ex][ey] == '#') continue;
                vis[ex][ey] = true;
                qx.push(ex), qy.push(ey);
            }
        }
    }
    int minPushBox(vector<vector<char>>& grid) {
        int stx = -1, sty = -1;
        int renx = -1, reny = -1;
        int n = grid.size(), m = grid[0].size();
        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j){
                if (grid[i][j] == 'B'){
                    stx = i, sty = j;
                }
                if (grid[i][j] == 'S'){
                    renx = i, reny = j;
                }
            }
        valid(grid, stx, sty, renx, reny);
        memset(st, 0x3f, sizeof(st));
        queue<pair<pair<int, int>, int> > q;
        for (int i = 0; i < 4; ++i){
            int ex = stx + dx[i], ey = sty + dy[i];
            if (ex < 0 || ex >= n || ey < 0 || ey >= m)
                continue;
            if (!vis[ex][ey]) continue;
            q.push(make_pair(make_pair(stx, sty), i));
            st[stx][sty][i] = 0;
        }
        int ans = 0x3f3f3f3f;
        while (!q.empty()){
            auto pp = q.front();
            q.pop();
            int oppo = (pp.second ^ 1);
            int cx = pp.first.first + dx[oppo], cy = pp.first.second + dy[oppo];
            // new posi for box
            if (cx < 0 || cx >= n || cy < 0 || cy >= m)
                continue;
            if (grid[cx][cy] == '#') continue;
            if (grid[cx][cy] == 'T'){
                // final
                ans = min(ans, st[pp.first.first][pp.first.second][pp.second]);
                continue;
            }
            valid(grid, cx, cy, pp.first.first, pp.first.second);
            int cur_step = st[pp.first.first][pp.first.second][pp.second];
            for (int i = 0; i < 4; ++i){
                int ex = cx + dx[i], ey = cy + dy[i];
                if (ex < 0 || ex >= n || ey < 0 || ey >= m)
                    continue;
                if (!vis[ex][ey]) continue;
                if (st[cx][cy][i] <= cur_step + 1)
                    continue;
                st[cx][cy][i] = cur_step + 1;
                q.push(make_pair(make_pair(cx, cy), i));
            }
        }
        if (ans == 0x3f3f3f3f)  
            return -1;
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
