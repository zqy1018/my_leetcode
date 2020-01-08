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

int sm[369], dp[369];
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(sm, 0, sizeof(sm));
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (auto x: days)
            sm[x] = 1;
        for (int i = 1; i <= 365; ++i)
            sm[i] += sm[i - 1];
        for (int i = 1; i <= 365; ++i){
            if (sm[i] == sm[i - 1])
                dp[i] = min(dp[i], dp[i - 1]);
            else dp[i] = min(dp[i], dp[i - 1] + costs[0]);
            if (sm[i] == sm[max(0, i - 7)])
                dp[i] = min(dp[i], dp[max(0, i - 7)]);
            else dp[i] = min(dp[i], dp[max(0, i - 7)] + costs[1]);
            if (sm[i] == sm[max(0, i - 30)])
                dp[i] = min(dp[i], dp[max(0, i - 30)]);
            else dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]);
        }
        return dp[365];
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
