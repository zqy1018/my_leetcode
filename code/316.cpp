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
    string removeDuplicateLetters(string s) {
        int cnt[26] = {0}, n = s.length();
        bool vis[26] = {0};
        for (int i = 0; i < n; ++i)
            ++cnt[s[i] - 'a'];
        string ans;
        for (int i = 0; i < n; --cnt[s[i] - 'a'], ++i){
            if (vis[s[i] - 'a']) 
                continue;
            while (!ans.empty() && s[i] <= ans.back()){
                if (!cnt[ans.back() - 'a'])
                    break;
                vis[ans.back() - 'a'] = false, ans.pop_back();
            }
            vis[s[i] - 'a'] = true, ans.push_back(s[i]);
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
