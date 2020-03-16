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
    int f[205][205];
    int numPermsDISequence(string S) {
        const int M = 1000000007;
        int l = S.length();
        f[0][1] = 1;
        for (int i = l - 1; i >= 0; --i){
            int tot = 0;            // 积累答案
            if (S[i] == 'D'){
                for (int j = 1; j <= l - i + 1; ++j)
                    f[l - i][j] = tot, tot = tot + f[l - i - 1][j] >= M ? tot + f[l - i - 1][j] - M: tot + f[l - i - 1][j];
            }else {
                for (int j = l - i; j >= 1; --j)
                    tot = tot + f[l - i - 1][j] >= M ? tot + f[l - i - 1][j] - M: tot + f[l - i - 1][j], f[l - i][j] = tot;
            }
        }
        int ans = 0;
        for (int i = 1; i <= l + 1; ++i)
            ans = (ans + f[l][i] >= M ? ans + f[l][i] - M: ans + f[l][i]);
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
