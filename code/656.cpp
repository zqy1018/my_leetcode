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
    int f[1005], mini[1005];
    bool vis[1005];
    vector<int> cheapestJump(vector<int>& A, int B) {
        int n = A.size();
        memset(f, 0x3f, sizeof(f));
        vector<int> ans;
        if (A[0] < 0 || A[n - 1] < 0) return ans;
        f[0] = A[0];
        for (int i = 0; i < n - 1; ++i)
            for (int j = min(B, n - 1 - i); j >= 1; --j)
                if (A[i + j] >= 0)
                    f[i + j] = min(f[i + j], f[i] + A[i + j]);
        if (f[n - 1] == 0x3f3f3f3f) return ans;
        memset(mini, 0x3f, sizeof(mini));
        queue<int> q;
        vis[n - 1] = true, q.push(n - 1);
        while (!q.empty()){
            int h = q.front();
            q.pop();
            for (int j = max(0, h - B); j < h; ++j)
                if (A[j] >= 0 && f[h] == f[j] + A[h]){
                    mini[j] = min(mini[j], h);
                    if (!vis[j]) vis[j] = true, q.push(j);
                }
        }
        ans.push_back(0);
        for (int i = 0; i != n - 1; i = mini[i])
            ans.push_back(mini[i]);
        ans.push_back(n - 1);
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
