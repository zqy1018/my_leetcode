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
    int countVowelPermutation(int n) {
        int f1 = 1, f2 = 1, f3 = 1, f4 = 1, f5 = 1;
        for (int i = 2; i <= n; ++i)    {
            long long ff1 = 0, ff2 = 0, ff3 = 0, ff4 = 0, ff5 = 0;
            ff2 += f1;
            ff1 += f2, ff3 += f2;
            ff1 += f3, ff2 += f3, ff4 += f3, ff5 += f3;
            ff3 += f4, ff5 += f4;
            ff1 += f5;
            ff1 %= 1000000007;
            ff2%= 1000000007;
            ff3 %= 1000000007;
            ff4 %= 1000000007;
            ff5 %= 1000000007;
            f1 = ff1, f2 = ff2, f3 = ff3, f4 = ff4, f5 = ff5;
        }
        long long ans = f1 + f2 + f3 + f4 + f5;
        ans %= 1000000007;
        return ans;
    }
};
Solution sol;
void init(){
    cout << sol.countVowelPermutation(5);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
