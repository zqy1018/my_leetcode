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
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size(), ans = 1;
        auto sgn = [](int x){ return x < 0 ? -1: (x == 0 ? 0: 1); };
        for (int i = 1; i < n; ++i){
            if (A[i] == A[i - 1]) continue;
            int j = i, f = sgn(A[i] - A[i - 1]);
            while (j < n && f == sgn(A[j] - A[j - 1]))
                ++j, f = -f;
            ans = max(ans, j - i + 1), i = j - 1;
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
