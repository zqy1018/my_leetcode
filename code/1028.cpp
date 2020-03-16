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
    pair<int, int> pp[1005];
    int tot;
    TreeNode* build(int l, int r){
        if (r > l) return nullptr;
        TreeNode* rt = new TreeNode(pp[l].first);
        for (int j = l + 2; j <= r; ++j){
            if (pp[j].second != pp[l].second + 1)
                continue;
            rt->left = build(l + 1, j - 1);
            rt->right = build(j, r);
            return rt;
        }
        rt->left = build(l + 1, r);
        return rt;
    }
    TreeNode* recoverFromPreorder(string S) {
        int l = S.length();
        tot = 0;
        for (int i = 0; i < l; ){
            int j = i;
            while (j < l && S[j] == '-')
                ++j;
            pp[tot].second = j - i;
            int x = 0;
            while (j < l && S[j] != '-')
                x = x * 10 + S[j] - '0', ++j;
            pp[tot++].first = x;
            i = j;
        }
        return build(0, tot - 1);
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
