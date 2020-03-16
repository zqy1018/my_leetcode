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

int mat[105][105], from[105], nn, mm;
bool vis[105];
bool unvisible[10][10];
int match(int x){
    for (int i = 0; i < nn * mm; ++i){
        int dx = i / mm, dy = i % mm;
        if ((dx + dy) & 1) continue;
        if (unvisible[dx][dy]) continue;
        if (!mat[x][i]) continue;
        if (!vis[i]){
            vis[i] = true;
            if (from[i] < 0 || match(from[i])){
                from[i] = x;
                return 1;
            }
        }
    }
    return 0;
}
int Hungary(){
    // 认为 (x 坐标 + y 坐标) 为奇数时格子是黑色，对黑色格子找匹配
    int match_size = 0;
    memset(from, -1, sizeof(from));
    for (int i = 0; i < nn * mm; ++i){
        int dx = i / mm, dy = i % mm;
        if (!((dx + dy) & 1)) continue;
        if (unvisible[dx][dy]) continue;
        memset(vis, 0, sizeof(vis));
        match_size += match(i);
    }
    return match_size;
}
class Solution {
public:
    int domino(int n, int m, vector<vector<int>>& broken) {
        nn = n, mm = m;
        memset(unvisible, 0, sizeof(unvisible));
        for (vector<int>& p: broken)
            unvisible[p[0]][p[1]] = true;
        memset(mat, 0, sizeof(mat));
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (unvisible[i][j]) continue;
                int id = i * m + j;     // 将节点按照 (x 坐标 * m) + (y 坐标) 编号
                if (j + 1 < m && unvisible[i][j + 1] == false){
                    int iid = i * m + j + 1;
                    mat[id][iid] = mat[iid][id] = 1;
                }
                if (i + 1 < n && unvisible[i + 1][j] == false){
                    int iid = (i + 1) * m + j;
                    mat[id][iid] = mat[iid][id] = 1;
                }
            }
        }
        return Hungary();
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
