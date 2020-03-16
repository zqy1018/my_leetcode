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
    int ten, K;
    bool vis[1005][10];
    string ans;
    void dfs(int cur){  
        for (int i = 0; i < K; ++i)
            if (!vis[cur][i]){
                vis[cur][i] = true;
                dfs((cur % ten) * 10 + i);
            }
        ans.push_back(cur % 10 + '0');
    }
    string crackSafe(int n, int k) {
        if (n == 1){
            for (int i = 0; i < k; ++i)
                ans.push_back(i + '0');
            return ans;
        }
        ten = 1, K = k;
        for (int i = 0; i < n - 2; ++i)
            ten *= 10;
        dfs(0);
        for (int i = 0; i < n - 2; ++i)
            ans.push_back('0');
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
