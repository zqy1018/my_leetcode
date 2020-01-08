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
    int numDecodings(string s) {
        int f2 = 1, f1 = 0, l = s.length();
        int M = 1000000007;
        if (s[0] == '*') f1 = 9;
        else if (s[0] != '0') f1 = 1;
        else return 0;
        for (int i = 1; i < l; ++i){
            int f0 = 0;
            if (s[i] == '*'){
                if (s[i - 1] == '*'){
                    f0 += 15ll * f2 % M;
                    f0 += 9ll * f1 % M;
                }else {
                    f0 += 9ll * f1 % M;
                    if (s[i - 1] == '1'){
                        f0 += 9ll * f2 % M;
                    }else if (s[i - 1] == '2'){
                        f0 += 6ll * f2 % M;
                    }
                }
            }else {
                if (s[i - 1] == '*'){
                    if (s[i] == '0'){
                        f0 += 2ll * f2 % M;
                    }else if (s[i] <= '6'){
                        f0 += f1;
                        f0 += 2ll * f2 % M;
                    }else {
                        f0 += f1;
                        f0 += f2;
                    }
                }else {
                    int t = 10 * (s[i - 1] - '0') + s[i] - '0';
                    if (s[i - 1] == '0'){
                        if (s[i] == '0') return 0;
                        f0 += f1;
                    }else {
                        if (t <= 26) f0 += f2;
                        if (s[i] != '0') f0 += f1;
                    }
                }
            }
            f0 %= M;
            f2 = f1, f1 = f0;
        }
        return f1;
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
