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
unsigned long long h[100005], M = 9982443, LM = 3535339, RM = 1000000007;
class Solution {
public: 
    vector<TreeNode*> ans;
    unordered_map<unsigned long long, int> st;
    pair<int, unsigned long long> dfs(TreeNode* cur) {
        if (cur == NULL) return make_pair(0, 0);
        auto pl = dfs(cur->left), pr = dfs(cur->right);
        int siz = 1 + pl.first + pr.first;
        unsigned long long hh = LM * pl.second * h[1 + pr.first] + (cur->val + M) * h[pr.first] + RM * pr.second;
        if (!st.count(hh))
            st[hh] = 1;
        else if (st[hh] == 1)
            ans.push_back(cur), st[hh] = 2;
        return make_pair(siz, hh);
    }   
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        h[0] = 1;
        for (int i = 1; i <= 100000; ++i)   
            h[i] = h[i - 1] * M;
        dfs(root);
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
