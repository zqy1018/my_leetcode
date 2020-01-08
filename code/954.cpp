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

int cntp[100005], cntn[100005];
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        int n = A.size();
        int cnt0 = 0, totp = 0, totn = 0;
        memset(cntp, 0, sizeof(cntp));
        memset(cntn, 0, sizeof(cntn));
        for (int x: A){
            if (x > 0) ++cntp[x], ++totp;
            else if (x == 0) ++cnt0;
            else ++cntn[-x], ++totn ;
        }
        if (cnt0 % 2) return false;
        if (totp % 2) return false;
        if (totn % 2) return false;
        for (int i = 1; i <= 50000; ++i){
            while (cntp[i]){
                if (!cntp[i + i])
                    return false;
                --cntp[i]   ,--cntp[i + i], totp -= 2;
            }
        }
        if (totp) return false;
        for (int i = 1; i <= 50000; ++i){
            while (cntn[i]){
                if (!cntn[i + i])
                    return false;
                --cntn[i]   ,--cntn[i + i], totn -= 2;
            }
        }
        if (totn) return false;
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
