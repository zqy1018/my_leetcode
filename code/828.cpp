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

int lst[30], lst2[30];
class Solution {
public:
    int uniqueLetterString(string S) {
        int n = S.length();
        if (!n) return 0;
        memset(lst, -1, sizeof(lst));
        memset(lst2, -1, sizeof(lst2));
        int ans = 0;
        for (int i = 0; i < n; ++i){
            int iid = S[i] - 'A';
            if (lst[iid] >= 0){
                int ll = lst[iid] - lst2[iid];
                int rr = i - lst[iid];
                ans += 1ll * ll * rr % 1000000007;
                if (ans >= 1000000007) ans -= 1000000007;
                lst2[iid] = lst[iid];
            }
            lst[iid] = i; 
        }
        for (int i = 0; i < 26; ++i){
            if (lst[i] >= 0){
                int ll = lst[i] - lst2[i];
                int rr = n - lst[i];
                ans += 1ll * ll * rr % 1000000007;
                if (ans >= 1000000007) ans -= 1000000007;
            }
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
