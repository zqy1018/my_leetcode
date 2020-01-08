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
    string strWithout3a3b(int A, int B) {
        string ans;
        if (A > B){
            int lim = min(B, A - B - 1);
            for (int i = 0; i < lim; ++i)
                ans.push_back('a'), ans.push_back('a'), ans.push_back('b'); 
            for (int i = 0; i < B - lim; ++i)
                ans.push_back('a'), ans.push_back('b');
            ans.push_back('a');
            if (A - B - 1 > B) ans.push_back('a');
        }else if (B > A){
            int lim = min(A, B - A - 1);
            for (int i = 0; i < lim; ++i)
                ans.push_back('b'), ans.push_back('b'), ans.push_back('a'); 
            for (int i = 0; i < A - lim; ++i)
                ans.push_back('b'), ans.push_back('a');
            ans.push_back('b');
            if (B - A - 1 > A) ans.push_back('b');
        }else {
            for (int i = 0; i < A; ++i)
                ans.push_back('a'), ans.push_back('b');
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
