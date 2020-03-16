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

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec){
    for (auto x: vec)
        os << x << " ";
    os << endl;
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<vector<T>>& vec){
    for (auto& v: vec){
        for (auto x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}

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
    int sm;
    long long ans;
    void dfs(TreeNode* cur){
        if (cur == nullptr) return ;
        sm += cur->val;
        dfs(cur->left);
        dfs(cur->right);
    }
    int dfs2(TreeNode* cur){
        if (cur == nullptr) return 0;
        int sml = dfs2(cur->left), smr = dfs2(cur->right);
        ans = max(ans, 1ll * (sm - sml) * sml);
        ans = max(ans, 1ll * (sm - smr) * smr);
        return sml + smr + cur->val;
    }
public:
    int maxProduct(TreeNode* root) {
        sm = 0, ans = 0;
        dfs(root);
        dfs2(root);
        return ans % 1000000007ll;
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
