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
    int cnt[30];
    bool vis[30];
    string rearrangeString(string s, int k) {
        if (!k) return s;
        int l = s.length(), maxi = 0;
        for (int i = 0; i < l; ++i)
            ++cnt[s[i] - 'a'];
        for (int i = 0; i < 26; ++i)    
            maxi = max(maxi, cnt[i]);
        if (maxi > (l - 1) / k + 1)
            return string("");
        string ans;
        for (int i = 0; i < l; ++i){
            int maxii = 0, p = -1;
            for (int j = 0; j < 26; ++j)
                if (!vis[j] && cnt[j] > maxii)
                    maxii = cnt[j], p = j;
            if (p == -1) return string("");
            vis[p] = true, ans.push_back(p + 'a');
            --cnt[p];
            if (i >= k - 1 && vis[ans[i - k + 1] - 'a'])
                vis[ans[i - k + 1] - 'a'] = false;
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
