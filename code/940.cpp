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

int f[2005], ssm, nxt[2005], lst[26];
class Solution {
public:
    int distinctSubseqII(string S) {
        memset(f, 0, sizeof(f));
        memset(lst, 0, sizeof(lst));
        const int M = 1000000007;
        int l = S.length();
        f[0] = 1, ssm = 1;
        for (int i = 1; i <= l; ++i){
            if (!lst[S[i - 1] - 'a'])
                lst[S[i - 1] - 'a'] = i, nxt[i] = 0;
            else 
                nxt[i] = lst[S[i - 1] - 'a'], lst[S[i - 1] - 'a'] = i;
        }
        for (int i = 1; i <= l; ++i){
            f[i] = ssm, ssm <<= 1;
            if (ssm >= M) ssm -= M;
            if (nxt[i] > 0){
                ssm += (M - f[nxt[i]]);
                if (ssm >= M) ssm -= M;                
            } 
        }
        return ssm;
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
