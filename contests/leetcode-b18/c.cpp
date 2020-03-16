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
    int tmp[105];
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for (int i = m - 1; i >= 0; --i){
            int tot = 0;
            for (int j = 0; j < n && i + j < m; ++j)
                tmp[tot++] = mat[j][i + j];
            sort(tmp, tmp + tot);
            for (int j = 0; j < n && i + j < m; ++j)
                mat[j][i + j] = tmp[j];
        }
        for (int i = 1; i < n; ++i){
            int tot = 0;
            for (int j = 0; j < m && i + j < n; ++j)
                tmp[tot++] = mat[i + j][j];
            sort(tmp, tmp + tot);
            for (int j = 0; j < m && i + j < n; ++j)
                mat[i + j][j] = tmp[j];
        }
        return mat;
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
