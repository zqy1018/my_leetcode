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


class Solution {
public:
    bool st[55][55][4], vis[55][55];
    int maxi[2505], n, m;
    queue<int> qx, qy;
    void bfs(int sx, int sy, int c, vector<vector<int>>& grid){
        qx.push(sx), qy.push(sy);
        grid[sx][sy] = c;
        vis[sx][sy] = true;
        while (!qx.empty()){
            sx = qx.front(), sy = qy.front();
            qx.pop(), qy.pop();
            for (int i = 0; i < 4; ++i){
                int cx = sx + dx[i], cy = sy + dy[i];
                if (cx < 0 || cy < 0 || cx >= n || cy >= m)
                    continue;
                if (grid[cx][cy] && !vis[cx][cy] && !st[sx][sy][i])
                    grid[cx][cy] = c, 
                    vis[cx][cy] = true, 
                    qx.push(cx), qy.push(cy);
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

const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
struct Rec{
    int c, cnt;
    int x1, y1, x2, y2;
    Rec(int _c): c(_c), cnt(0), x1(100), y1(100), x2(-1), y2(-1){} 
};
class Solution {
public:
    int n, m;
    bool vis[55][55];
    vector<Rec> vec;
    queue<int> qx, qy;
    void bfs(int sx, int sy, int c, vector<vector<int>>& grid){
        Rec tmp(c);
        qx.push(sx), qy.push(sy);
        grid[sx][sy] = c;
        vis[sx][sy] = true;
        while (!qx.empty()){
            sx = qx.front(), sy = qy.front();
            qx.pop(), qy.pop();
            tmp.x1 = min(tmp.x1, sx);
            tmp.y1 = min(tmp.y1, sy);
            tmp.x2 = max(tmp.x2, sx);
            tmp.y2 = max(tmp.y2, sy);
            ++tmp.cnt;
            for (int i = 0; i < 4; ++i){
                int cx = sx + dx[i], cy = sy + dy[i];
                if (cx < 0 || cy < 0 || cx >= n || cy >= m)
                    continue;
                if (grid[cx][cy] && !vis[cx][cy])
                    grid[cx][cy] = c, 
                    vis[cx][cy] = true, 
                    qx.push(cx), qy.push(cy);
            }
        }
        vec.push_back(tmp);
    }
    bool check(vector<vector<int>>& grid){
        int nn = vec.size();
        Rec& cur = vec.back();
        int c = cur.c;
        int cx1 = cur.x1, cx2 = cur.x2, cy1 = cur.y1, cy2 = cur.y2;
        int xsize = cx2 - cx1, ysize = cy2 - cy1;
        for (int T = 0; T < nn - 1; ++T){
            int cc = vec[T].c, ccnt = vec[T].cnt;
            if (ccnt != cur.cnt) continue;
            int xx1 = vec[T].x1, xx2 = vec[T].x2, yy1 = vec[T].y1, yy2 = vec[T].y2;
            int xxsize = xx2 - xx1, yysize = yy2 - yy1;
            bool flag;
            if (xxsize == xsize && yysize == ysize){
                flag = true;
                for (int i = 0; i <= xsize && flag; ++i)
                    for (int j = 0; j <= ysize; ++j)
                        if (grid[cx1 + i][cy1 + j] == c && grid[xx1 + i][yy1 + j] != cc){
                            flag = false;
                            break;
                        }
                if (flag) return false;
                flag = true;
                for (int i = 0; i <= xsize && flag; ++i)
                    for (int j = 0; j <= ysize; ++j)
                        if (grid[cx1 + i][cy1 + j] == c && grid[xx1 + i][yy2 - j] != cc){
                            flag = false;
                            break;
                        }
                if (flag) return false;
                flag = true;
                for (int i = 0; i <= xsize && flag; ++i)
                    for (int j = 0; j <= ysize; ++j)
                        if (grid[cx1 + i][cy1 + j] == c && grid[xx2 - i][yy1 + j] != cc){
                            flag = false;
                            break;
                        }
                if (flag) return false;
                flag = true;
                for (int i = 0; i <= xsize && flag; ++i)
                    for (int j = 0; j <= ysize; ++j)
                        if (grid[cx1 + i][cy1 + j] == c && grid[xx2 - i][yy2 - j] != cc){
                            flag = false;
                            break;
                        }
                if (flag) return false;
            }
            if (yysize == xsize && xxsize == ysize){
                flag = true;
                for (int i = 0; i <= xsize && flag; ++i)
                    for (int j = 0; j <= ysize; ++j)
                        if (grid[cx1 + i][cy1 + j] == c && grid[xx1 + j][yy1 + i] != cc){
                            flag = false;
                            break;
                        }
                if (flag) return false;
                flag = true;
                for (int i = 0; i <= xsize && flag; ++i)
                    for (int j = 0; j <= ysize; ++j)
                        if (grid[cx1 + i][cy1 + j] == c && grid[xx2 - j][yy1 + i] != cc){
                            flag = false;
                            break;
                        }
                if (flag) return false;
                flag = true;
                for (int i = 0; i <= xsize && flag; ++i)
                    for (int j = 0; j <= ysize; ++j)
                        if (grid[cx1 + i][cy1 + j] == c && grid[xx1 + j][yy2 - i] != cc){
                            flag = false;
                            break;
                        }
                if (flag) return false;
                flag = true;
                for (int i = 0; i <= xsize && flag; ++i)
                    for (int j = 0; j <= ysize; ++j)
                        if (grid[cx1 + i][cy1 + j] == c && grid[xx2 - j][yy2 - i] != cc){
                            flag = false;
                            break;
                        }
                if (flag) return false;
            }
        }
        return true;
    }
    int numDistinctIslands2(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int tot_color = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (!vis[i][j] && grid[i][j]){
                    ++tot_color, bfs(i, j, tot_color, grid);
                    if (!check(grid)) vec.pop_back();
                }
        return vec.size();
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
