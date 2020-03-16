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
    int n;
    bool check(vector<vector<int>>& board){
        int lst_0 = -1, lst_1 = -1;
        for (int i = 0; i < n; ++i){
            if (board[0][i]){
                if (lst_1 < 0) lst_1 = i;
                else {
                    for (int j = 0; j < n; ++j)
                        if (board[j][i] != board[j][lst_1])
                            return false;
                }
            }else {
                if (lst_0 < 0) lst_0 = i;
                else{
                    for (int j = 0; j < n; ++j)
                        if (board[j][i] != board[j][lst_0])
                            return false;
                }
            }
        }
        for (int i = 0; i < n; ++i)
            if (board[i][lst_0] == board[i][lst_1])
                return false;
        return true;
    }
    int movesToChessboard(vector<vector<int>>& board) {
        n = board.size();
        if (n & 1){
            // 奇数行
            int hf = (n >> 1), hff = hf + 1;
            int c = 0;
            for (int i = 0; i < n; ++i){
                int cnt = 0;
                for (int j = 0; j < n; ++j)
                    cnt += board[i][j];
                if (cnt == hf) ++c;        // 0 更多
                else if (cnt != hff) return -1;                  
            }
            int cl = 0;
            for (int i = 0; i < n; ++i){
                int cnt = 0;
                for (int j = 0; j < n; ++j)
                    cnt += board[j][i];
                if (cnt == hf) ++cl;        // 0 更多
                else if (cnt != hff) return -1;     
            }
            if (cl != c) return -1;
            if (c != hf && c != hff) return -1;
            if (!check(board)) return -1;
            int ans = 0, r0_1 = 0, c0_1 = 0;
            for (int i = 0; i < n; ++i)
                r0_1 += board[0][i], 
                c0_1 += board[i][0];
            r0_1 -= hf, c0_1 -= hf;
            for (int i = 0; i < n; i += 2)
                ans += (r0_1 ^ board[0][i]) + (c0_1 ^ board[i][0]); 
            return ans;
        }else {
            int hf = (n >> 1);
            for (int i = 0; i < n; ++i){
                int c1 = 0, c2 = 0;
                for (int j = 0; j < n; ++j)
                    c1 += board[i][j], 
                    c2 += board[j][i];
                if (c1 != hf || c2 != hf) return -1;
            }
            if (!check(board)) return -1;
            int ans1 = 0, ans2 = 0;
            for (int i = 0; i < n; i += 2)
                ans1 += 1 - board[0][i], 
                ans2 += 1 - board[i][0];
            ans1 = min(ans1, hf - ans1);
            ans2 = min(ans2, hf - ans2);
            return ans1 + ans2;
        }
        return 0;
    }
};
Solution sol;
void init(){
    vector<vector<int>> vec{{1, 0, 0}, {0, 1, 1}, {1, 0, 0}};
    cout << sol.movesToChessboard(vec) << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
