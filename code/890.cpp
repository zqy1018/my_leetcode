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
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int inj[26] = {0}, surj[26] = {0};
        for (string& str: words){
            bool flag = true;
            for (int i = 0; i < 26; ++i) inj[i] = surj[i] = -1;
            int n = str.length();
            for (int i = 0; i < n; ++i){
                char c1 = str[i] - 'a', c2 = pattern[i] - 'a';
                if ((inj[c1] >= 0 && inj[c1] != c2) || (surj[c2] >= 0 && surj[c2] != c1)) {
                    flag = false;
                    break;
                }
                inj[c1] = c2, surj[c2] = c1;
            }
            if (flag) ans.push_back(str);
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
