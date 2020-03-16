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
    int tm[50005];
    int kEmptySlots(vector<int>& bulbs, int K) {
        int n = bulbs.size();
        for (int i = 0; i < n; ++i)
            tm[bulbs[i] - 1] = i + 1;
        int l = 0, r = K + 1, ans = n + 1;
        while (r < n){
            bool flag = true;
            int targ = max(tm[l], tm[r]);
            for (int i = l + 1; i < r; ++i)
                if (tm[i] < targ){
                    l = i, r = i + K + 1;
                    flag = false;
                    break;
                }
            if (flag)
                ans = min(ans, targ),
                l = r, r += K + 1;
        }
        if (ans > n) return -1;
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
