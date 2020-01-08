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
    void manacher(string& s, vector<int>& res){
        int n = s.length();
        res[0] = 0;
        for (int i = 1; i < (n << 1) - 1; ++i) res[i] = -1;
        for (int i = 1, rmost = 0; i < (n << 1) - 1; ++i){
            int l = (i >> 1), r = i - l, rpos = ((rmost + 1) >> 1) + res[rmost] - 1;
            if ((rmost << 1) >= i)
                res[i] = min(rpos - r + 1, res[(rmost << 1) - i]);
            while (l - res[i] - 1 >= 0 && r + res[i] + 1 < n 
                && s[l - res[i] - 1] == s[r + res[i] + 1])
                ++res[i];
            if (r + res[i] - 1 > rpos)
                rmost = i;
        } 
    }
    string shortestPalindrome(string s) {
        int n = s.length(), ans = 0;
        vector<int> res((n << 1) - 1, 0);
        manacher(s, res);
        for (int i = 0; i < (n << 1) - 1; ++i){
            if (res[i] + 1 - (i & 1) == ((i + 1) >> 1))
                ans = max(ans, (res[i] << 1) + (i & 1) + 1);
        }
        string sans = s;
        reverse(sans.begin(), sans.end());
        for (int i = ans; i < n; ++i)   
            sans.push_back(s[i]);
        return sans;
    }
};
Solution sol;
void init(){
    cout << sol.shortestPalindrome("abcd") << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
