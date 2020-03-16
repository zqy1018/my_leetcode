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
    int cnt[20005], n, tot, cur1, cur2, ans;
    inline void upd(vector<int>& A, int K){
        while (tot < K && cur1 < n){
            if (!cnt[A[cur1]])
                ++tot;
            ++cnt[A[cur1]];
            ++cur1;
        }
        if (cur2 < cur1) cur2 = cur1;
        while (cur2 < n){
            if (!cnt[A[cur2]])
                break;
            ++cur2;
        }
        if (tot == K)
            ans += cur2 - cur1 + 1;
    }
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        n = A.size();
        tot = ans = cur1 = cur2 = 0;
        upd(A, K);
        for (int i = 1; i < n; ++i){
            if (cnt[A[i - 1]] == 1)
                --tot;
            --cnt[A[i - 1]];
            upd(A, K);
            // cout << ans << endl;
        }
        return ans;
    }
};
Solution sol;
void init(){
    vector<int> vec{1,2,1,3,4};
    cout << sol.subarraysWithKDistinct(vec, 3) << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
