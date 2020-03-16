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
    bool st[55][55][4], vis[55][55];
    int maxi[2505], n, m;
    int q[2505][2], hd, tl;
    void bfs(int sx, int sy, int c, vector<vector<int>>& grid){
        hd = tl = 0;
        q[tl][0] = sx, q[tl++][1] = sy;
        grid[sx][sy] = c;
        vis[sx][sy] = true;
        while (tl > hd){
            sx = q[hd][0], sy = q[hd++][1];
            for (int i = 0; i < 4; ++i){
                int cx = sx + dx[i], cy = sy + dy[i];
                if (cx < 0 || cy < 0 || cx >= n || cy >= m)
                    continue;
                if (grid[cx][cy] && !vis[cx][cy] && !st[sx][sy][i])
                    grid[cx][cy] = c, 
                    vis[cx][cy] = true, 
                    q[tl][0] = cx, q[tl++][1] = cy;
            }
        }
    }
    int color(vector<vector<int>>& grid){
        int tot_color = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] && !vis[i][j])
                    ++tot_color, bfs(i, j, tot_color, grid);
        return tot_color;
    }
    void count(vector<vector<int>>& grid){
        int cnt = 0, cand[4];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j){
                if (grid[i][j]) continue;
                int cnt_nb = 0;
                for (int d = 0; d < 4; ++d){
                    int cx = i + dx[d], cy = j + dy[d];
                    if (cx < 0 || cy < 0 || cx >= n || cy >= m)
                        continue;
                    if (!st[i][j][d] && grid[cx][cy]) 
                        cand[cnt_nb++] = grid[cx][cy];
                }
                sort(cand, cand + cnt_nb);
                int real_cnt_nb = unique(cand, cand + cnt_nb) - cand;
                for (int d = 0; d < real_cnt_nb; ++d)
                    ++maxi[cand[d]];
            }
    }
    int build(int c, vector<vector<int>>& grid){
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j){
                if (grid[i][j] != c) continue;
                for (int d = 0; d < 4; ++d){
                    int cx = i + dx[d], cy = j + dy[d];
                    if (cx < 0 || cy < 0 || cx >= n || cy >= m)
                        continue;
                    if (!grid[cx][cy] && !st[i][j][d]) 
                        ++cnt, 
                        st[i][j][d] = st[cx][cy][d ^ 1] = true;
                }
            }
        return cnt;
    }
    void expand(vector<vector<int>>& grid){
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j){
                if (grid[i][j]) continue;
                for (int d = 0; d < 4; ++d){
                    int cx = i + dx[d], cy = j + dy[d];
                    if (cx < 0 || cy < 0 || cx >= n || cy >= m)
                        continue;
                    if (!st[i][j][d] && grid[cx][cy] > 0)     // 直接接触
                        grid[i][j] = -1;
                }
            }
    }
    void show(vector<vector<int>>& grid){       // 调试用
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    int containVirus(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (; ; ){
            int tot_color = color(grid);
            memset(maxi, 0, sizeof(int) * (tot_color + 1));
            count(grid);
            int p = -1, maxii = 0;
            for (int i = 1; i <= tot_color; ++i)
                if (maxi[i] > maxii) 
                    maxii = maxi[i], p = i;
            if (maxii == 0) return ans;
            ans += build(p, grid);
            expand(grid);
        }
    }
};

Solution sol;
void init(){
    vector<vector<int>> vec = 
        {{0,0,1,1,1,0,1,0,0,0},{1,1,1,0,0,0,1,1,0,1},{0,0,0,0,0,0,1,0,0,0},{0,0,0,0,1,0,1,0,0,0},{1,0,0,0,1,1,1,0,0,0},{0,0,0,1,0,1,1,0,0,0},{1,0,0,0,0,1,0,0,0,1},{1,0,0,0,0,0,0,0,0,1},{0,1,0,0,0,0,0,0,1,0},{1,1,0,0,0,1,0,1,0,0}};
    cout << sol.containVirus(vec) << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
