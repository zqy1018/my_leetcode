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
    vector<int> ans;
    vector<int> cheapestJump(vector<int>& A, int B) {
        memset(f, 0x3f, sizeof(f));
        memset(mini, 0x3f, sizeof(mini));
        int n = A.size();        
        if (A[0] < 0 || A[n - 1] < 0) return ans;
        f[n] = A[n - 1];
        for (int i = n - 1; i >= 1; --i){
            for (int j = max(1, i - B); j < i; ++j){
                if (A[j] < 0) continue;
                if (f[i] + A[j - 1] < f[j])
                    f[j] = f[i] + A[j - 1], 
                    mini[j] = min(mini[j], i);
            }
        }
        if (f[1] == 0x3f3f3f3f) return ans;
        for (int i = 1; i < n; i = mini[i])
            ans.push_back(i);
        ans.push_back(n);
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
