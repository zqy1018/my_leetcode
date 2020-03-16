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

int f[105][105], g[105][105];
class Solution {
public:
    int palindromePartition(string s, int k) {
        memset(f, 0x3f, sizeof(f));
        memset(g, 0x3f, sizeof(g));
        int l = s.length();
        for (int i = 0; i < l; ++i){
            g[i + 1][i + 1] = 0;
            for (int j = i + 1; j < l; ++j){
                int tot = 0;
                for (int lp = i, rp = j; lp < rp; ++lp, --rp)
                    if (s[lp] != s[rp])
                        ++tot;
                g[i + 1][j + 1] = tot;
            }
        }
        f[0][0] = 0;
        for (int i = 1; i <= k; ++i)
            for (int j = 1; j <= l; ++j)
                for (int t = 0; t < j; ++t)
                    f[i][j] = min(f[i][j], f[i - 1][t] + g[t + 1][j]);
        return f[k][l];
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
