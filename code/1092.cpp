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
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0x3f3f3f3f));
        vector<vector<char>> bef(n + 1, vector<char>(m + 1, 0));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i)
            f[i][0] = i, bef[i][0] = 1;
        for (int i = 1; i <= m; ++i)
            f[0][i] = i, bef[0][i] = 3;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                if (str1[i - 1] == str2[j - 1]){
                    f[i][j] = f[i - 1][j - 1] + 1, bef[i][j] = 2;
                }else{
                    if (f[i][j - 1] > f[i - 1][j])
                        f[i][j] = f[i - 1][j] + 1, bef[i][j] = 1;
                    else 
                        f[i][j] = f[i][j - 1] + 1, bef[i][j] = 3;
                }
            }
        }
        string ans;
        for (int i = n, j = m; i || j; ){
            if (bef[i][j] == 1)
                ans.push_back(str1[i - 1]), --i;
            else if (bef[i][j] == 2)
                ans.push_back(str1[i - 1]), --i, --j;
            else 
                ans.push_back(str2[j - 1]), --j;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
Solution sol;
void init(){
    cout << sol.shortestCommonSupersequence("bbbaaaba", "bbababbb");
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
