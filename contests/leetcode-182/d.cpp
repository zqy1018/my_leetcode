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

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec){
    for (auto x: vec)
        os << x << " ";
    os << endl;
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<vector<T>>& vec){
    for (auto& v: vec){
        for (auto x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}

const int M = 1000000007;
class Solution {
    int nxt[55];
    int f[505][55][2];
    int fd[55][27];
    int subp(int n, string& s, string& e){
        memset(f, 0, sizeof(f));
        int l = e.length();
        f[0][0][1] = 1;
        for (int i = 1; i <= n; ++i){
            for (int j = 0; j < 26; ++j){
                for (int t = 0; t < l; ++t){
                    f[i][fd[t][j]][0] = (f[i][fd[t][j]][0] + f[i - 1][t][0]) % M;
                    if (j < s[i - 1] - 'a')
                        f[i][fd[t][j]][0] = (f[i][fd[t][j]][0] + f[i - 1][t][1]) % M;
                    else if (j == s[i - 1] - 'a')
                        f[i][fd[t][j]][1] = (f[i][fd[t][j]][1] + f[i - 1][t][1]) % M;
                }
            }
        }
        int res = 0;
        for (int j = 0; j < l; ++j){
            res = (res + f[n][j][0]) % M;
            res = (res + f[n][j][1]) % M;
        }
        return res;
    }
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        nxt[0] = -1;
        int l = evil.size();
        for (int j = -1, i = 1; i < l; ++i){
            while (j > -1 && evil[i] != evil[j + 1])
                j = nxt[j];
            if (evil[i] == evil[j + 1])
                nxt[i] = ++j;
            else nxt[i] = -1;
        }
        for (int i = -1; i < l - 1; ++i){
            for (int j = 0; j < 26; ++j){
                if (evil[i + 1] - 'a' == j)
                    fd[i + 1][j] = i + 1 + 1;
                else {
                    if (i == -1) fd[0][j] = 0;
                    else fd[i + 1][j] = fd[nxt[i] + 1][j];
                }
            }
        }
        int res1 = subp(n, s2, evil), res2 = subp(n, s1, evil);
        int ans = (res1 + M - res2) % M;
        if (s1.find(evil) == string::npos) 
            ans = (ans + 1) % M;
        return ans;
    }
};
Solution sol;
void init(){
    cout << sol.findGoodStrings(8, "pzdanyao", "wgpmtywi", "sdka");
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
