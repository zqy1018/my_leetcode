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
    int n, cur;
    bool calc(string& expr){
        if (isalpha(expr[cur])) return (expr[cur] == 't' ? true: false);
        if (expr[cur] == '!') {
            cur += 2;
            bool res = !calc(expr);
            ++cur;
            return res;
        }
        bool flag = (expr[cur] == '&' ? true: false), res = flag;
        for (; ; ){
            cur += 2;
            if (flag)
                res &= calc(expr);
            else 
                res |= calc(expr);
            if (expr[cur + 1] == ')')
                break;
        }
        ++cur;
        return res;
    }
    bool parseBoolExpr(string expression) {
        n = expression.length(), cur = 0;
        return calc(expression);
    }
};
Solution sol;
void init(){
    cout << sol.parseBoolExpr("|(&(t,f,t),!(t))");
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
