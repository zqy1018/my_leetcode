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
    int f[105][105], g[105][105];
    int gt(char c){
        if (isalpha(c)) return 0;
        return c - '0';
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int M = 1000000007;
        int n = board.size(), m = board[0].size();
        for (int i = n - 2; i >= 0; --i)
            if (board[i][m - 1] != 'X' && board[i + 1][m - 1] != 'X')
                f[i][m - 1] = f[i + 1][m - 1] + gt(board[i][m - 1]);
        for (int j = m - 2; j >= 0; --j){
            if (board[n - 1][j] != 'X' && board[n - 1][j + 1] != 'X') 
                f[n - 1][j] = f[n - 1][j + 1] + gt(board[n - 1][j]);
            for (int i = n - 2; i >= 0; --i)
                if (board[i][j] != 'X'){
                    int tt = 0;
                    if (board[i + 1][j + 1] != 'X') tt = max(tt, f[i + 1][j + 1]);
                    if (board[i][j + 1] != 'X') tt = max(tt, f[i][j + 1]);
                    if (board[i + 1][j] != 'X') tt = max(tt, f[i + 1][j]);
                    f[i][j] = tt + gt(board[i][j]);
                }
        }
        g[n - 1][m - 1] = 1;
        for (int i = n - 2; i >= 0; --i)
            if (board[i][m - 1] != 'X')
                g[i][m - 1] = g[i + 1][m - 1];
        for (int j = m - 2; j >= 0; --j){
            if (board[n - 1][j] != 'X')
                g[n - 1][j] = g[n - 1][j + 1];
            for (int i = n - 2; i >= 0; --i)
                if (board[i][j] != 'X'){
                    if (f[i][j] == gt(board[i][j]) + f[i + 1][j + 1])   
                        g[i][j] = (g[i][j] + g[i + 1][j + 1]) % M;
                    if (f[i][j] == gt(board[i][j]) + f[i + 1][j])   
                        g[i][j] = (g[i][j] + g[i + 1][j]) % M;
                    if (f[i][j] == gt(board[i][j]) + f[i][j + 1])   
                        g[i][j] = (g[i][j] + g[i][j + 1]) % M;
                }
        }
        vector<int> ans;
        ans.push_back(f[0][0]);
        ans.push_back(g[0][0]);
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
