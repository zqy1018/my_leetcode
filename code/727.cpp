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
    int f[20005][105];
    string minWindow(string S, string T) {
        memset(f, 0x3f, sizeof(f));
        int n = S.length(), m = T.length();
        for (int i = 0; i < n; ++i){
            if (S[i] == T[0]) f[i + 1][1] = 1;
            else f[i + 1][1] = f[i][1]; 
        }
        for (int j = 1; j < m; ++j){
            int mini = 0x3f3f3f3f;
            for (int i = 0; i < n; ++i){
                if (S[i] == T[j]){
                    if (mini < 0x3f3f3f3f){
                        f[i + 1][j + 1] = min(f[i][j + 1], mini + i + 1);
                    }else f[i + 1][j + 1] = f[i][j + 1];
                }else {
                    f[i + 1][j + 1] = f[i][j + 1];
                }
                if (f[i + 1][j] < 0x3f3f3f3f && S[i] == T[j - 1])
                    mini = min(mini, f[i + 1][j] - i - 1);
                cout << i << " " << j << " " << f[i + 1][j + 1] << " "  << mini << endl;
            }
        }
        if (f[n][m] == 0x3f3f3f3f) return string("");
        int ans = f[n][m];
        for (int i = 0; i < n; ++i)
            if (f[i + ans][m] == ans)
                return S.substr(i, ans);
        return string("");
    }
};
Solution sol;
void init(){
    string a("abcdebdde"), b("bde");
    cout << sol.minWindow(a, b) << endl;

}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
