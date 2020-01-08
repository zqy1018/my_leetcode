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
    int checkRecord(int n) {
        int f0 = 1, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0;
        for (int i = 0; i < n; ++i){
            int ff0 = ((f0 + f1) % 1000000007 + f2) % 1000000007;
            int ff1 = f0;
            int ff2 = f1;
            int ff3 = ((f3 + f4) % 1000000007 + f5) % 1000000007;
            ff3 += f6;
            if (ff3 >= 1000000007) ff3 -= 1000000007;
            int ff4 = (f3 + f6) % 1000000007;
            int ff5 = f4;
            int ff6 = ((f0 + f1) % 1000000007 + f2) % 1000000007;
            f0 = ff0, f1 = ff1, f2 = ff2, f3 = ff3, 
            f4 = ff4, f5 = ff5, f6 = ff6;
        }
        int ans = f0 + f1;
        if (ans >= 1000000007) ans -= 1000000007;
        ans += f2;
        if (ans >= 1000000007) ans -= 1000000007;
        ans += f3;
        if (ans >= 1000000007) ans -= 1000000007;
        ans += f4;
        if (ans >= 1000000007) ans -= 1000000007;
        ans += f5;
        if (ans >= 1000000007) ans -= 1000000007;
        ans += f6;
        if (ans >= 1000000007) ans -= 1000000007;
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
