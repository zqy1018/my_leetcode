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
int dis[65][6][32][32], pos[10][2], logg[65];
int f[65][6];
bool vis[65][6];
class Solution {
public:
    queue<int> qx, qy;
    void bfs(vector<string>& grid, int sx, int sy, int di, int dj){
        int n = grid.size(), m = grid[0].size();
        qx.push(sx), qy.push(sy);
        dis[di][dj][sx][sy] = 0;
        while (!qx.empty()){
            int cx = qx.front(), cy = qy.front();
            qx.pop(), qy.pop();
            int step = dis[di][dj][cx][cy];
            for (int i = 0; i < 4; ++i){
                int ex = cx + dx[i], ey = cy + dy[i];
                if (ex < 0 || ex >= n || ey < 0 || ey >= m)
                    continue;
                if (grid[ex][ey] == '#' || dis[di][dj][ex][ey] < 0x3f3f3f3f) continue;
                if (isupper(grid[ex][ey]) && ((1 << (grid[ex][ey] - 'A')) & di) == 0)
                    continue;
                dis[di][dj][ex][ey] = step + 1;
                qx.push(ex), qy.push(ey);
            }
        }
    }
    int dfs(int di, int dj){
        if (vis[di][dj]) return f[di][dj];
        if ((di & (-di)) == di) f[di][dj] = dis[0][0][pos[dj][0]][pos[dj][1]];
        else {
            int p = (1 << dj);
            for (int i = di - p, j = (i & (-i)); i > 0; i -= j, j = (i & (-i)))
                f[di][dj] = min(f[di][dj], dfs(di - p, logg[j]) + dis[di - p][logg[j]][pos[dj][0]][pos[dj][1]]);
        }
        if (di == 1 && dj == 0)
            cout << f[1][0] << endl;
        vis[di][dj] = true;
        return f[di][dj];
    }
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        int sx, sy;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j){
                if (islower(grid[i][j]))
                    pos[grid[i][j] - 'a'][0] = i, 
                    pos[grid[i][j] - 'a'][1] = j, ++cnt;
                else if (grid[i][j] == '@')
                    sx = i, sy = j;
            }
        int lim = (1 << cnt);
        logg[1] = 0, logg[2] = 1, logg[4] = 2, 
        logg[8] = 3, logg[16] = 4, logg[32] = 5;

        memset(dis[0][0], 0x3f, sizeof(dis[0][0]));
        bfs(grid, sx, sy, 0, 0);
        memset(f, 0x3f, sizeof(f));
        memset(vis, 0, sizeof(vis));

        for (int i = 1; i < lim - 1; ++i){
            for (int j = i, k = (j & (-j)); j > 0; j -= k, k = (j & (-j))){
                int id = logg[k];
                memset(dis[i][id], 0x3f, sizeof(dis[i][id]));
                bfs(grid, pos[id][0], pos[id][1], i, id);
            }
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < cnt; ++i)   
            ans = min(ans, dfs(lim - 1, i)); 
        
        for (int i = 0; i < lim; ++i)
            for (int j = 0; j < cnt; ++j)
                cout << i << " " << j << " " << f[i][j] << endl;
        return (ans == 0x3f3f3f3f ? -1: ans);
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
