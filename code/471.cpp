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
    int f[166][166], ans[166][166];
    bool zip[166][166];
    int nxt[166][166];
    string aans;
    void build(int l, int r, string& s){
        if (zip[l][r]){
            int ll = r - l + 1;
            int len = ll - 1 - nxt[l][ll - 1];
            aans += to_string(ll / len);
            aans.push_back('[');
            build(l, l + len - 1, s);
            aans.push_back(']');
            return ;
        }
        if (ans[l][r] == -1){
            for (int i = l; i <= r; ++i)
                aans.push_back(s[i]);
            return ;
        }
        build(l, ans[l][r], s);
        build(ans[l][r] + 1, r, s);
    }
    inline int calc_len(int x){
        int res = 0;
        while (x > 0)
            ++res, x /= 10;
        return res;
    }
    string encode(string s) {
        int l = s.length();
        for (int i = 0; i < l; ++i){
            nxt[i][0] = -1;
            for (int t = -1, j = 1; j < l - i; ++j){
                while (t > -1 && s[i + t + 1] != s[i + j])
                    t = nxt[i][t];
                if (s[i + t + 1] == s[i + j])
                    nxt[i][j] = ++t;
                else nxt[i][j] = -1;
            }
        }
        // zip 为 true 时 ans 为 -1
        // 为 false 时 ans 为 -1 表示不改动
        // 长度 <= 4 不必改动
        for (int t = 1; t <= 4; ++t)
            for (int i = 0; i + t <= l; ++i)
                zip[i][i + t - 1] = false, 
                ans[i][i + t - 1] = -1, 
                f[i][i + t - 1] = t;
        for (int t = 5; t <= l; ++t){
            for (int i = 0; i + t <= l; ++i){
                int& tg = f[i][i + t - 1];
                zip[i][i + t - 1] = false, 
                ans[i][i + t - 1] = -1, 
                tg = t;
                // 尝试压缩
                int len = t - 1 - nxt[i][t - 1];
                if (len < t && t % len == 0){
                    zip[i][i + t - 1] = true, 
                    tg = calc_len(t / len) + 2 + f[i][i + len - 1];
                }
                // 尝试组合
                for (int j = i; j < i + t - 1; ++j){
                    int targ = f[i][j] + f[j + 1][i + t - 1];
                    if (targ < tg)
                        tg = targ, 
                        ans[i][i + t - 1] = j, 
                        zip[i][i + t - 1] = false;
                } 
            }
        }
        build(0, l - 1, s);
        return aans;
    }
};
Solution sol;
void init(){
    string ss("aaaaa");
    cout << sol.encode(ss) << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
