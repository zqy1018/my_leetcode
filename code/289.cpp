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

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        if (!n) return ;
        int m = board[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j){
                int cnt = 0;
                for (int k = 0; k < 8; ++k){
                    int cx = i + dx[k], cy = j + dy[k];
                    if (cx < 0 || cy < 0 || cx >= n || cy >= m)
                        continue;
                    if (board[cx][cy] & 1) ++cnt;
                }
                if ((board[i][j] && cnt >= 2 && cnt <= 3) || (!board[i][j] && cnt == 3))  
                    board[i][j] |= 2;
            }
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                board[i][j] >>= 1;
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
