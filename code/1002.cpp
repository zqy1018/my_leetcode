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
    vector<string> commonChars(vector<string>& A) {
        vector<string> ans;
        int cnt[26] = {0}, cnt2[26] = {0};
        for (int i = 0; i < 26; ++i)
            cnt2[i] = 101;
        for (string& str: A){
            for (int i = 0; i < 26; ++i)
                cnt[i] = 0;
            for (char c: str)
                ++cnt[c - 'a'];
            for (int i = 0; i < 26; ++i)
                cnt2[i] = min(cnt2[i], cnt[i]);
        }
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < cnt2[i]; ++j)
                ans.push_back(string(1, i + 'a'));
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
