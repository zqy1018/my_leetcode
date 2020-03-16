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

int gray[70000];
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans;
        for (int i = 0; i < (1 << n); ++i)
            gray[i] = (i ^ (i >> 1));
        int pos = 0;
        for (int i = 0; i < (1 << n); ++i)
            if (gray[i] == start) {
                pos = i;
                break;
            }
        for (int i = pos; i < (1 << n); ++i)
            ans.push_back(gray[i]);
        for (int i = 0; i < pos; ++i)
            ans.push_back(gray[i]);
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
