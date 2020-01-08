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
    string smallestSubsequence(string text) {
        int cnt[26] = {0}, n = text.length();
        bool vis[26] = {0};
        for (int i = 0; i < n; ++i)
            ++cnt[text[i] - 'a'];
        string ans;
        for (int i = 0; i < n; --cnt[text[i] - 'a'], ++i){
            if (vis[text[i] - 'a']) 
                continue;
            while (!ans.empty() && text[i] <= ans.back()){
                if (!cnt[ans.back() - 'a'])
                    break;
                vis[ans.back() - 'a'] = false, ans.pop_back();
            }
            vis[text[i] - 'a'] = true, ans.push_back(text[i]);
        }
        return ans;
    }
};
Solution sol;
void init(){
    cout << sol.smallestSubsequence("bcbcbcababa");
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
