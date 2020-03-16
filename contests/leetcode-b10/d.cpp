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

int f[1005][1005];
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        memset(f, 0x3f, sizeof(f));
        int n = s.length();
        for (int i = 0; i < n; ++i)
            f[i][i] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                f[i][j] = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j + i < n; ++j){
                if (s[j] == s[j + i])   
                    f[j][j + i] = f[j + 1][j + i - 1];
                else f[j][j + i] = min(f[j][j + i - 1], f[j + 1][i + j]) + 1;
            }
        }
        return f[0][n - 1] <= k;
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
