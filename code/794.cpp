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
    bool win(vector<string>& board, char c){
        for (int i = 0; i < 3; ++i)
            if (board[i][0] == board[i][1] && board[i][0] == board[i][2] 
                && board[i][0] == c)
                return true; 
        for (int i = 0; i < 3; ++i)
            if (board[0][i] == board[1][i] && board[0][i] == board[2][i] 
                && board[0][i] == c)
                return true;
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2] 
            && board[0][0] == c)
            return true;
        if (board[0][2] == board[1][1] && board[0][2] == board[2][0] 
            && board[0][2] == c)
            return true;
        return false;
    }
    bool validTicTacToe(vector<string>& board) {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j){
                if (board[i][j] == 'O') ++cnt2;
                else if (board[i][j] == 'X') ++cnt1;
            }
        if (cnt1 == cnt2 + 1){
            // no player2 win
            return !win(board, 'O');
        }else if (cnt1 == cnt2){
            return !win(board, 'X');
        }else return false;
        return true;
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
