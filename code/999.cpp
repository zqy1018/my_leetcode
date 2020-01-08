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
    int numRookCaptures(vector<vector<char>>& board) {
        int x = -1, y = -1;
        for (int i = 0; i < 8 && x < 0; ++i)
            for (int j = 0; j < 8; ++j)
                if (board[i][j] == 'R'){
                    x = i, y = j;
                    break;
                }
        int ans = 0;
        for (int i = x - 1; i >= 0; --i){
            if (board[i][y] == 'B') break;
            if (board[i][y] == 'p') {
                ++ans;
                break;
            }
        }
        for (int i = x + 1; i < 8; ++i){
            if (board[i][y] == 'B') break;
            if (board[i][y] == 'p') {
                ++ans;
                break;
            }
        }
        for (int i = y - 1; i >= 0; --i){
            if (board[x][i] == 'B') break;
            if (board[x][i] == 'p') {
                ++ans;
                break;
            }
        }
        for (int i = y + 1; i < 8; ++i){
            if (board[x][i] == 'B') break;
            if (board[x][i] == 'p') {
                ++ans;
                break;
            }
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
