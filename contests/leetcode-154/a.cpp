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
    int maxNumberOfBalloons(string text) {
        int cnt[26] = {0};
        for (char c: text)
            ++cnt[c - 'a'];
        int ans = INT_MAX;
        ans = min(ans, cnt['b' - 'a']);
        ans = min(ans, cnt['a' - 'a']);
        ans = min(ans, cnt['l' - 'a'] >> 1);
        ans = min(ans, cnt['o' - 'a'] >> 1);
        ans = min(ans, cnt['n' - 'a']);
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
