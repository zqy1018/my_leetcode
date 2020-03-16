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

int sum[305][305];
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j)
                sum[i + 1][j + 1] = sum[i + 1][j] + matrix[i][j];
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j)
                sum[i + 1][j + 1] += sum[i][j + 1];
        int lim = min(n, m), ans = 0;
        for (int L = 1; L <= lim; ++L)
            for (int i = L; i <= n; ++i)
                for (int j = L; j <= m; ++j){
                    int t = sum[i][j] - sum[i - L][j] - sum[i][j - L] + sum[i - L][j - L];
                    if (t == L * L)
                        ++ans;
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
