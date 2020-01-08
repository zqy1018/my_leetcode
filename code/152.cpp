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
    int maxProduct(vector<int>& nums) {
        int ans = -2147483648;
        int n = nums.size();
        for (int i = 0, pp = 1; i < n; ++i, pp = (pp == 0 ? 1: pp))
            pp *= nums[i], ans = max(ans, pp);
        for (int i = n - 1, pp = 1; i >= 0; --i, pp = (pp == 0 ? 1: pp))
            pp *= nums[i], ans = max(ans, pp);
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
