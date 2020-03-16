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

int f[505], ff[505];
class Solution {
public:
    int numWays(int steps, int arrLen) {
        memset(f, 0, sizeof(f));
        f[0] = 1;
        int M = 1000000007;
        int lim = min(steps, arrLen - 1);
        for (int i = 1; i <= steps; ++i)    {
            ff[0] = (f[0] + f[1]) % M;
            for (int j = 1; j <= lim; ++j)
                ff[j] = (f[j - 1] + f[j]) % M, 
                ff[j] = (ff[j] + f[j + 1]) % M;
            for (int j = 0; j <= steps; ++j)
                f[j] = ff[j];
        }
        return f[0];
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
