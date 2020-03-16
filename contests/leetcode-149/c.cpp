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
    int maxRepOpt1(string text) {
        int cnt[26] = {0}, n = text.size();
        for (int i = 0; i < n; ++i) 
            cnt[text[i] - 'a']++;
        int ans = 1, lstblock = 0;
        for (int i = 0; i < n; ){
            int j = i;
            while (j < n && text[i] == text[j])
                ++j;
            if (j - i == 1){
                if (i == 0){
                    if (j != n){
                        int t = j;
                        while (t < n && text[j] == text[t])
                            ++t;
                        int all = cnt[text[j] - 'a'];
                        if (t - j < all)
                            ans = max(ans, t - j + 1);
                    }
                }else if (j == n){
                    int all = cnt[text[i - 1] - 'a'];
                    if (lstblock < all)
                        ans = max(ans, lstblock + 1);
                }else {
                    int t = j;
                    while (t < n && text[j] == text[t])
                        ++t;
                    if (text[i - 1] == text[j]){
                        int all = cnt[text[j] - 'a'];
                        if (lstblock + t - j < all)
                            ans = max(ans, lstblock + t - j + 1);
                        else ans = max(ans, lstblock + t - j);
                    }
                }
            }else {
                ans = max(ans, j - i);
                if (j - i < cnt[text[i] - 'a'])
                    ans = max(ans, j - i + 1);
            }
            lstblock = j - i, i = j;
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
