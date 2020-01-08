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
    int nextGreaterElement(int n) {
        int perm[11], len = 0;
        int tmp = n;
        while (tmp > 0)
            perm[len++] = tmp % 10, tmp /= 10;
        for (int i = 0; i < (len >> 1); ++i)
            swap(perm[i], perm[len - 1 - i]);
        if (!next_permutation(perm, perm + len))
            return -1;
        long long u = 0;
        for (int i = 0; i < len; ++i)
            u = u * 10 + perm[i];
        if (u > INT_MAX)
            return -1;
        return u;
    }
};
Solution sol;
void init(){
    
}
void solve(){
    // sol.convert();
}
int main(){
    int T = read();
    while (T--){
 init();
    solve();
    }
    return 0;
}
