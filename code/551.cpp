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
    bool checkRecord(string s) {
        bool cnt = false;
        int n = s.length();
        for (int i = 0; i < n; ){
            int j = i;
            while (j < n && s[i] == s[j])
                ++j;
            if (s[i] == 'A'){
                if (j - i > 1 || cnt) return false;
                cnt = true;
            }else if (s[i] == 'L'){
                if (j - i > 2) return false;
            }
            i = j;
        }
        return true;
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
