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
    int f[505][505];
    int minInsertions(string s) {
        int l = s.length();
        for (int i = 0; i < l; ++i){
            for (int j = 0; j < l; ++j){
                if (s[i] == s[l - j - 1]){
                    f[i + 1][j + 1] = 1 + f[i][j];
                }else {
                    f[i + 1][j + 1] = max(f[i + 1][j], f[i][j + 1]);
                }
            }
        }
        // single
        int ans = l;
        for (int i = 0; i < l; ++i){
            int dis = l - 1 - f[i][l - i - 1];
            ans = min(ans, dis);
        }
        // double
        for (int i = 0; i < l - 1; ++i){
            if (s[i] != s[i + 1]) continue;
            int dis = l - 2 - f[i][l - i - 2];
            ans = min(ans, dis);
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
