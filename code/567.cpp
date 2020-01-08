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
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();
        if (l1 > l2) return false;
        int cnt[26] = {0}, tot = 0;
        for (char c: s1)
            ++cnt[c - 'a'];
        for (int i = 0; i < 26; ++i) 
            if (cnt[i]) ++tot;
        for (int i = 0; i < l1; ++i){
            --cnt[s2[i] - 'a'];
            if (cnt[s2[i] - 'a'] == 0) --tot;
            else if (cnt[s2[i] - 'a'] == -1) ++tot;
        }
        for (int i = l1; i < l2; ++i){
            if (!tot) return true;
            ++cnt[s2[i - l1] - 'a'];
            if (cnt[s2[i - l1] - 'a'] == 0) --tot;
            else if (cnt[s2[i - l1] - 'a'] == 1) ++tot;
            --cnt[s2[i] - 'a'];
            if (cnt[s2[i] - 'a'] == 0) --tot;
            else if (cnt[s2[i] - 'a'] == -1) ++tot;
        }
        if (!tot) return true;
        return false;
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
