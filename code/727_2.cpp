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
    int f[2][20005];
    string minWindow(string S, string T) {
        int n = S.length(), m = T.length();
        for (int i = 0; i < n; ++i)
            if (S[i] == T[0]) f[1][i + 1] = 1;
            else f[1][i + 1] = 0x3f3f3f3f;
        for (int j = 1; j < m; ++j){
            int mini = 0x3f3f3f3f;
            int B = (j + 1) & 1, B_ = B ^ 1;
            for (int i = 0; i < n; ++i){
                if (S[i] == T[j] && mini < 0x3f3f3f3f)
                    f[B][i + 1] = mini + i + 1;
                else f[B][i + 1] = 0x3f3f3f3f;
                if (f[B_][i + 1] < 0x3f3f3f3f)
                    mini = min(mini, f[B_][i + 1] - i - 1);
            }
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i)
            ans = min(ans, f[m & 1][i + 1]);
        if (ans == 0x3f3f3f3f) return string("");
        for (int i = 0; i < n; ++i)
            if (f[m & 1][i + ans] == ans)
                return S.substr(i, ans);
        return string("");
    }
};
Solution sol;


void init(){
    string a("cnhczmccqouqadqtmjjzl"), b("mm");
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
