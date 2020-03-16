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

int minl[205], minr[205], f[205][205];
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        memset(f, 0x3f, sizeof(f));
        minl[0] = minr[n + 1] = 0x3f3f3f3f;
        for (int i = 1; i <= n; ++i)
            minl[i] = minr[i] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                f[i][j] = arr[i - 1][j - 1] + min(minl[j - 1], minr[j + 1]);
            for (int j = 1; j <= n; ++j)
                minl[j] = min(minl[j - 1], f[i][j]);
            for (int j = n; j >= 1; --j)    
                minr[j] = min(minr[j + 1], f[i][j]);
        }
        int ans = 0x3f3f3f3f;
        for (int i = 1; i <= n; ++i)
            ans = min(ans, f[n][i]);
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
