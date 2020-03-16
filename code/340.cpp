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
    int cnt[130], l, tot, cur;
    inline void upd(string& s, int k){
        while (tot < k && cur < l){
            if (!cnt[s[cur]])
                ++tot;
            ++cnt[s[cur]];
            ++cur;
        }
        while (cur < l){
            if (!cnt[s[cur]])
                break;
            ++cnt[s[cur]];
            ++cur;
        }
    }
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        l = s.length();
        tot = 0, cur = 0;
        upd(s, k);
        if (cur == l) return l;
        int ans = cur;
        for (int i = 1; i < l; ++i){
            if (cnt[s[i - 1]] == 1)
                --tot;
            --cnt[s[i - 1]];
            upd(s, k);
            ans = max(ans, cur - i);
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
