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
    vector<int> sm;
    int dfs(TreeNode* cur){
        if (cur == NULL) return 0;
        int siz = cur->val + dfs(cur->left) + dfs(cur->right);
        sm.push_back(siz);
        return siz;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans; 
        dfs(root);
        sort(sm.begin(), sm.end());
        int n = sm.size(), maxi = 1;
        for (int i = 0; i < n; ){
            int j = i;
            while (j < n && sm[i] == sm[j])
                ++j;
            maxi = max(maxi, j - i);
            i = j;
        }
        for (int i = 0; i < n; ){
            int j = i;
            while (j < n && sm[i] == sm[j])
                ++j;
            if (j - i == maxi) ans.push_back(sm[i]);
            i = j;
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
