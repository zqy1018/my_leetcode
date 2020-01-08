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
    int minFallingPathSum(vector<vector<int>>& A) {
        int f[2][105] = {0}, n = A.size();
        for (int i = 0; i < n; ++i)
            f[0][i] = A[0][i];
        for (int i = 1; i < n; ++i){
            int B = (i & 1), B_ = 1 - B;
            f[B][0] = min(f[B_][0], f[B_][1]) + A[i][0];
            for (int j = 1; j < n - 1; ++j)
                f[B][j] = min(f[B_][j - 1], min(f[B_][j], f[B_][j + 1])) + A[i][j];
            f[B][n - 1] = min(f[B_][n - 1], f[B_][n - 2]) + A[i][n - 1];
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i)
            ans = min(ans, f[(n - 1) & 1][i]);
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
