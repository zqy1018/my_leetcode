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
    int maxRotateFunction(vector<int>& A) {
        long long sm = accumulate(A.begin(), A.end(), 0ll);
        long long acc = 0;
        int n = A.size(), ans = INT_MIN;
        for (int i = 0; i < n; ++i)
            acc += i * A[i];
        for (int i = 0; i < n; ++i)
            ans = max(ans, int(acc - i * sm)), 
            acc -= i * A[i], 
            acc += 1ll * (i + n) * A[i];
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
