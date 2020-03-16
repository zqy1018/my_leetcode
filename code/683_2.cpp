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
    int c[20005], n;
    bool vis[20005];
    inline int lowbit(int x){
        return x & (-x);
    }
    int query(int r){
        int res = 0;
        while (r > 0)
            res += c[r], r -= lowbit(r);
        return res;
    }
    void add(int r){
        while (r <= n)
            c[r] += 1, r += lowbit(r);
    }
    int kEmptySlots(vector<int>& bulbs, int K) {
        n = bulbs.size();
        for (int i = 0; i < n - K; ++i){
            int x = bulbs[i];
            add(x), vis[x] = true;
            int ll = query(x - K - 1), mid = query(x), rr = query(x + K + 1);
            if ((x + K + 1 <= n && vis[x + K + 1] && rr == mid + 1) || 
                (x - K - 1 > 0 && vis[x - K - 1] && mid == ll + 1))
                return i + 1;
        }
        return -1;
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
