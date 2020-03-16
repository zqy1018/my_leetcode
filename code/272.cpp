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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    void dfs(TreeNode* cur){
        if (cur == nullptr) return ;
        dfs(cur->left);
        res.push_back(cur->val);
        dfs(cur->right);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        dfs(root);
        double l = 0.0, r = 1e8;
        while (r - l > 1e-5){
            double mid = (l + r) * 0.5;
            int cnt = 0;
            for (int x: res)
                if (fabs(x - target) < mid) ++cnt;
            if (cnt < k) l = mid;
            else r = mid;
        }
        vector<int> ans;
        for (int x: res)
            if (fabs(x - target) < l) ans.push_back(x);
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
