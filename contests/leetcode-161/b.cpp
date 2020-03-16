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

int sum[50005], len[50005];
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for (int &t: nums)
            t = (t & 1);
        sum[0] = 0;
        int ans = 0, n = nums.size();
        for (int i = 1; i <= n; ++i)    
            sum[i] = sum[i - 1] + nums[i - 1];
        memset(len, 0, sizeof(len));
        for (int i = 0; i < n; ++i)
            ++len[sum[i]];
        for (int i = 1; i <= n; ++i){
            if (sum[i] - k >= 0)
                ans += len[sum[i] - k];
        }
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
