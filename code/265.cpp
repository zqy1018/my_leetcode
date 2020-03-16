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
    int f[1005], g[1005], h[1005];
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size();
        for (int i = 1; i <= k; ++i)
            f[i] = costs[0][i - 1];
        g[0] = h[k + 1] = 0x3f3f3f3f;
        for (int i = 1; i < n; ++i){
            for (int j = 1; j <= k; ++j)
                g[j] = min(g[j - 1], f[j]),
                h[k - j + 1] = min(h[k - j + 2], f[k - j + 1]);
            for (int j = 1; j <= k; ++j)
                f[j] = min(g[j - 1], h[j + 1]) + costs[i][j - 1];
        }
        int ans = 0x3f3f3f3f;
        for (int i = 1; i <= k; ++i)
            ans = min(ans, f[i]);
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
