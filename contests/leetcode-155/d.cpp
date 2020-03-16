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


Solution sol;
void init(){
    vector<int> vec{-1,-1,1,0,0,1,0,-1};
    vector<vector<int>> vec2{{}, {6}, {5}, {6}, {3}, {}, {4}, {}};
    cout << sol.sortItems(8, 2, vec, vec2).size();
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
