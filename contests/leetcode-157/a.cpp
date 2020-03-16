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
    int minCostToMoveChips(vector<int>& chips) {
        sort(chips.begin(), chips.end());
        int n = chips.size();
        int ans = 2000000000;
        for (int i = 0 ;i < n; ++i){
            for (int j = -1; j < 2; ++j){
                int cnt = 0;
                for (int k = 0; k < n; ++k)
                    if (abs(chips[k] - chips[i] + j) & 1)
                        ++cnt;
                ans = min(ans, cnt);
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
