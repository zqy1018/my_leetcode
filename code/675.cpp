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
class Solution {
public:
    map<int, pair<int, int>> mp;
    vector<pair<int, int>> vec;
    vector<vector<int>> dis;
    vector<vector<bool>> vis;
    queue<int> qx, qy;
    void bfs(int n, int m, int tx, int ty, vector<vector<int>>& forest){
        while (!qx.empty()){
            int cx = qx.front(), cy = qy.front();
            qx.pop(), qy.pop();
            if (cx == tx && cy == ty) 
                break ;
            for (int i = 0; i < 4; ++i){
                int ex = cx + dx[i], ey = cy + dy[i];
                if (ex < 0 || ex >= n || ey < 0 || ey >= m)
                    continue ;
                if (vis[ex][ey] || forest[ex][ey] == 0)
                    continue ;
                dis[ex][ey] = dis[cx][cy] + 1;
                vis[ex][ey] = true;
                qx.push(ex), qy.push(ey);
            }
        }
        while (!qx.empty()) 
            qx.pop(), qy.pop();
    }
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest[0][0] == 0)
            return -1;
        int n = forest.size(), m = forest[0].size();
        dis = vector<vector<int>>(n, vector<int>(m, 0));
        vis = vector<vector<bool>>(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (forest[i][j] > 1){
                    mp[forest[i][j]] = make_pair(i, j);
                }
            }
        }
        for (auto k: mp)
            vec.push_back(k.second);
        int t = vec.size(), lstx = 0, lsty = 0, ans = 0;
        for (int i = 0; i < vec.size(); ++i){
            auto p = vec[i];
            qx.push(lstx), qy.push(lsty);
            dis[lstx][lsty] = 0, vis[lstx][lsty] = true;
            bfs(n, m, p.first, p.second, forest);
            if (!vis[p.first][p.second])
                return -1;
            ans += dis[p.first][p.second];
            lstx = p.first, lsty = p.second;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    vis[i][j] = false;
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
