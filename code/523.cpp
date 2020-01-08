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
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ssm = 0;
        if (!k) {
            for (int i = 0; i < n - 1; ++i)
                if (!nums[i] && !nums[i + 1])
                    return true;
            return false;
        }else if (k < 0) k = -k;
        unordered_map<int, int> mp;
        mp[0] = 0;
        for (int i = 1; i <= n; ++i){
            ssm += nums[i - 1] % k;
            if (ssm >= k) ssm -= k;
            if (mp.count(ssm) && mp[ssm] < i - 1)   
                return true;
            else if (!mp.count(ssm)) mp[ssm] = i; 
        }
        return false;
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
