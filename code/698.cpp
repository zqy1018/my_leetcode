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
    int sum;
    bool vis[20];
    bool judge(int t, vector<int>& nums){
        
    }
    bool dfs(int cur, vector<int>& nums, int bt, int sm){
        
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        memset(vis, 0, sizeof(vis));
        int n = nums.size(), maxi = 0;
        sum = 0;
        for (int i = 0; i < n; ++i)
            sum += nums[i], maxi = max(maxi, nums[i]);
        if (sum % k || maxi > sum / k) return false;
        return dfs(0, nums, 0, 0);
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
