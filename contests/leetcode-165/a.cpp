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

int pp[10][10];
class Solution {
public:
    int check(){
        for (int i = 0; i < 3; ++i)
            if (pp[i][0] == pp[i][1] && pp[i][1] == pp[i][2] && pp[i][0] != 0)
                return pp[i][0];
        for (int i = 0; i < 3; ++i)
            if (pp[0][i] == pp[1][i] && pp[1][i] == pp[2][i] && pp[0][i] != 0)
                return pp[0][i];
        if (pp[0][0] == pp[1][1] && pp[0][0] == pp[2][2] && pp[0][0] != 0)
            return pp[0][0];
        if (pp[0][2] == pp[1][1] && pp[0][2] == pp[2][0] && pp[0][2] != 0)
            return pp[0][2];
        return 0;
    }
    string tictactoe(vector<vector<int>>& moves) {
        memset(pp, 0, sizeof(pp));
        int cnt = 0;
        for (auto& v: moves){
            if (cnt & 1){
                // B
                pp[v[0]][v[1]] = 1;
            }else {
                // A
                pp[v[0]][v[1]] = -1;
            }
            int ff = check();
            if (ff == -1) return string("A");
            else if (ff == 1) return string("B");
            ++cnt;
        }
        if (moves.size() == 9) return string("Draw");
        return string("Pending");
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
