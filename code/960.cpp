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

int f[105];
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        memset(f, 0, sizeof(f));
        int l = A[0].length(), ans = 1;
        f[0] = 1;
        for (int i = 1; i < l; ++i){
            f[i] = 1;
            for (int j = 0; j < i; ++j){
                bool flag = true;
                for (auto& s: A)
                    if (s[i] < s[j]){
                        flag = false;
                        break;
                    }
                if (flag) f[i] = max(f[i], f[j] + 1);
            }
            ans = max(ans, f[i]);
        }
        return l - ans;
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
