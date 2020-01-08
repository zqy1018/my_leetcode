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
    int bestRotation(vector<int>& A) {
        int n = A.size(), tot = 0;
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; ++i) 
            if (i >= A[i])
                ++cnt[i - A[i]], ++tot;
        int p = 0, maxi = -1;
        for (int i = 0; i < n; ++i){
            if (tot > maxi) maxi = tot, p = i;
            tot -= cnt[i];
            if (i - A[i] >= 0) 
                --cnt[i - A[i]];
            else ++cnt[n + i - A[i]];
            if (A[i] < n) ++tot;
        }
        return p;
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
