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

double f[1005][1005];
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= target; ++j)
                f[i][j] = 0;
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i){
            f[i][0] = f[i - 1][0] * (1.0 - prob[i - 1]);
            for (int j = 1; j <= target; ++j)
                f[i][j] = f[i - 1][j] * (1.0 - prob[i - 1]) + f[i - 1][j - 1] * prob[i - 1];
        }
        return f[n][target];
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
