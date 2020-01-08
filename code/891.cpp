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
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(), A.end());
        int ans = 0, n = A.size(), M = 1000000007;
        int sum2 = 0, mi = 1, tmp;
        for (int i = 1; i < n; ++i){
            sum2 = (sum2 + sum2 >= M ? sum2 + sum2 - M: sum2 + sum2);
            mi = (mi + mi >= M ? mi + mi - M: mi + mi);
            tmp = 1ll * (A[i] - A[i - 1]) * (mi - 1) % M;
            sum2 = (sum2 + tmp >= M ? sum2 + tmp - M: sum2 + tmp);
            ans = (ans + sum2 >= M ? ans + sum2 - M: ans + sum2);
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
