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

int f[105][105], pos[26][105];
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        memset(f, 0x3f, sizeof(f));
        for (int i = 0; i < 26; ++i)
            pos[i][0] = 0;
        int n = ring.length(), m = key.length();
        for (int i = 0; i < n; ++i){
            int c = ring[i] - 'a';
            pos[c][++pos[c][0]] = i;
        }
        for (int i = 1; i <= pos[key[0] - 'a'][0]; ++i)
            f[0][i] = min(pos[key[0] - 'a'][i], n - pos[key[0] - 'a'][i]);
        for (int i = 1; i < m; ++i){
            int t1 = key[i - 1] - 'a', t2 = key[i] - 'a';
            for (int j = 1; j <= pos[t1][0]; ++j)
                for (int k = 1; k <= pos[t2][0]; ++k){
                    int opt1 = (pos[t1][j] - pos[t2][k] + n) % n, 
                        opt2 = (pos[t2][k] - pos[t1][j] + n) % n;
                    f[i][k] = min(f[i][k], f[i - 1][j] + min(opt1, opt2));                    
                }
        }
        int ans = 0x3f3f3f3f;
        for (int i = 1; i <= pos[key[m - 1] - 'a'][0]; ++i)
            ans = min(ans, f[m - 1][i]);
        return ans + m;
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
