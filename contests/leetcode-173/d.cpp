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
    int maxi[305][305];
    int f[15][305];
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;
        for (int i = 0; i < n; ++i){
            maxi[i][i] = jobDifficulty[i];
            for (int j = i + 1; j < n; ++j)
                maxi[i][j] = max(maxi[i][j - 1], jobDifficulty[j]);
        }
        memset(f, 0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= d; ++i){
            for (int j = i; j <= n - d + i; ++j){
                for (int k = i - 1; k < j; ++k)
                    f[i][j] = min(f[i][j], f[i - 1][k] + maxi[k][j - 1]);
            }
        }
        return f[d][n];
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
