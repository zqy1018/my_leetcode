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

bool vis[27][100005];
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        memset(vis, 0, sizeof(vis));
        int l = p.length();
        auto nxt = [](char x){ return (x == 'z' ? 'a': x + 1); };
        for (int i = 0; i < l; ){
            int j = i + 1;
            while (j < l && p[j] == nxt(p[j - 1]))
                ++j;
            int ll = j - i;
            for (int t = 1; t <= ll; ++t)
                for (int h = i; h + t <= j && h < i + 26; ++h)
                    vis[p[h] - 'a'][t] = true;
            i = j;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i)
            for (int j = 1; j <= l; ++j)    
                ans += (vis[i][j] ? 1: 0);
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
