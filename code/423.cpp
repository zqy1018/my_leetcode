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
    string originalDigits(string s) {
        int cnt[26] = {0}, tot[10] = {0}, totu = 0;
        string ans;
        for (char c: s) ++cnt[c - 'a'];
        tot[0] = cnt['z' - 'a'];
        cnt['o' - 'a'] -= cnt['z' - 'a'], cnt['r' - 'a'] -= cnt['z' - 'a'];
        tot[2] = cnt['w' - 'a'];
        cnt['o' - 'a'] -= cnt['w' - 'a'];
        tot[4] = cnt['u' - 'a'];
        cnt['o' - 'a'] -= cnt['u' - 'a'], cnt['r' - 'a'] -= cnt['u' - 'a'], cnt['f' - 'a'] -= cnt['u' - 'a'];
        tot[6] = cnt['x' - 'a'];
        cnt['i' - 'a'] -= cnt['x' - 'a'];
        tot[8] = cnt['g' - 'a'];
        cnt['i' - 'a'] -= cnt['g' - 'a'];
        tot[1] = cnt['o' - 'a'];
        tot[3] = cnt['r' - 'a'];
        tot[5] = cnt['f' - 'a'];
        cnt['v' - 'a'] -= cnt['f' - 'a'], cnt['i' - 'a'] -= cnt['f' - 'a'];
        tot[7] = cnt['v' - 'a'];
        tot[9] = cnt['i' - 'a'];
        for (int v: tot) totu += v;
        ans.reserve(totu);
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < tot[i]; ++j)
                ans.push_back(i + '0');
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
