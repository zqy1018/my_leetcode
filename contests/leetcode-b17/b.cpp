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
    int sm[105][105];
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                sm[i + 1][j + 1] = sm[i + 1][j] + mat[i][j];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                sm[i + 1][j + 1] += sm[i][j + 1];
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                int cx = min(i + K + 1, n), cy = min(j + K + 1, m);
                int dx = max(i - K, 0), dy = max(j - K, 0);
                ans[i][j] = sm[cx][cy] - sm[cx][dy] - sm[dx][cy] + sm[dx][dy];
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
