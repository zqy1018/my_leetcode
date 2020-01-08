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
    bool vis[3][11][11]; // 0 行 1 列 2 宫 
    int lis[81][2], len_lis;
    void get(int at){
        int mini = 99, targ = -1;
        for(int i = at + 1; i < len_lis; ++i){
            int x = lis[i][0], y = lis[i][1], o = 0;
            for(int j = 1; j <= 9; ++j){
                if(vis[0][x][j] || vis[1][y][j] || vis[2][(x / 3) * 3 + y / 3][j])
                    continue;
                ++o;
            }
            if(o < mini) mini = o, targ = i;
        }
        swap(lis[targ][0], lis[at + 1][0]);
        swap(lis[targ][1], lis[at + 1][1]);
    }
    bool dfs(int at, vector<vector<char>>& board){
        int x = lis[at][0], y = lis[at][1];
        int block_id = (x / 3) * 3 + y / 3;
        for(int i = 1; i <= 9; ++i){
            if (vis[0][x][i] || vis[1][y][i] || vis[2][block_id][i])
                continue;
            vis[0][x][i] = vis[1][y][i] = vis[2][block_id][i] = true, 
            board[x][y] = i + '0';
            if(at < len_lis - 1){
                if (at != len_lis - 2) get(at);
                if (dfs(at + 1, board))
                    return true;
            }else return true;
            vis[0][x][i] = vis[1][y][i] = vis[2][block_id][i] = 0;
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        memset(vis, 0, sizeof(vis));
        memset(lis, 0, sizeof(lis));
        len_lis = 0;
        for (int i = 0; i < 9; ++i) 
            for (int j = 0; j < 9; ++j){
                if (board[i][j] == '.'){
                    lis[len_lis][0] = i, lis[len_lis++][1] = j;
                }else {
                    int id = board[i][j] - '0';
                    vis[0][i][id] = vis[1][j][id] = vis[2][(i / 3) * 3 + j / 3][id] = true;
                }
            }
        dfs(0, board);
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


