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
    bool PredictTheWinner(vector<int>& nums) {
        int f[25][25] = {0}, n = nums.size(), ssm = 0;
        for (int i = 0; i < n - 1; ++i)
            f[i][i] = nums[i], f[i][i + 1] = max(nums[i], nums[i + 1]), ssm += nums[i];
        f[n - 1][n - 1] = nums[n - 1], ssm += nums[n - 1];
        for (int i = 2; i < n; ++i){
            for (int j = 0; j + i < n; ++j){
                f[j][j + i] = max(nums[j] + min(f[j + 2][j + i], f[j + 1][j + i - 1]), 
                        nums[j + i] + min(f[j][j + i - 2], f[j + 1][j + i - 1]));
            }
        }
        return f[0][n - 1] >= ssm - f[0][n - 1];
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
