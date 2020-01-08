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
    int numPrimeArrangements(int n) {
        bool vis[105] = {0};
        int cnt = 0;
        for (int i = 2; i <= n; ++i) {
            if (!vis[i]){
                ++cnt;
                for (int j = i + i; j <= n; j += i)
                    vis[j] = true;  
            }
        }
        int fac[105] = {0};
        fac[0] = 1;
        for (int i = 1; i <= n; ++i)
            fac[i] = 1ll * fac[i - 1] * i % 1000000007;
        return 1ll * fac[cnt] * fac[n - cnt] % 1000000007;
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
