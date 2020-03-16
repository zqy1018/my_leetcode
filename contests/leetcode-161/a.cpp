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
    int minimumSwap(string s1, string s2) {
        int c1 =0 , c2 = 0;
        int l = s1.length();
        for (int i = 0; i < l; ++i)   {
            if (s1[i] == 'x') ++c1;
            else ++c2;
            if (s2[i] == 'x') ++c1;
            else ++c2;
        } 
        if ((c1 & 1) || (c2 & 1))
            return -1;
        int c3 = 0, c4 = 0;
        for (int i = 0; i < l; ++i){
            if (s1[i] == 'x' && s1[i] != s2[i])
                ++c3;
            else if (s1[i] == 'y' && s1[i] != s2[i])
                ++c4;
        }
        int ans = 0;
        ans += (c3 >> 1) + (c4 >> 1);
        c3 %= 2, c4 %= 2;
        if (c3 && c4) ans += 2;
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
