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
    int nxt[2005][2005];
    int distinctEchoSubstrings(string text) {
        int l = text.length();
        for (int i = 0; i < l; ++i) {
            nxt[i][0] = -1;
            for (int t = i + 1, j = -1; t < l; ++t){
                while (j > -1 && text[i + j + 1] != text[t])
                    j = nxt[i][j];
                if (text[i + j + 1] == text[t])
                    nxt[i][t - i] = ++j;
                else nxt[i][t - i] = -1; 
            }
        }
        map<string, int> mp;
        int ans = 0;
        for (int i = l; i >= 2; --i){
            for (int j = 0; j + i <= l; ++j){
                int len = i - 1 - nxt[j][i - 1];
                if (len < i && i % len == 0){
                    int tt = i / len;
                    ans += tt - 1;
                    auto ss = text.substr(j, i);
                    if (!mp.count(ss))
                        mp[ss] = tt;
                    else mp[ss] = max(mp[ss], tt);
                }
            }
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
