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
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0x3f3f3f3f));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i)
            f[i][0] = f[i - 1][0] + s1[i - 1];
        for (int i = 1; i <= m; ++i)
            f[0][i] = f[0][i - 1] + s2[i - 1];
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                if (s1[i - 1] == s2[j - 1]){
                    f[i][j] = f[i - 1][j - 1];
                }else {
                    f[i][j] = min(f[i - 1][j] + s1[i - 1], f[i][j - 1] + s2[j - 1]);
                }
            }
        }
        return f[n][m];
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
