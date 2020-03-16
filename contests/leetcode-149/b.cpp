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
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> ff(d + 1, vector<int>(target + 1, 0));
        ff[0][0] = 1;
        for (int i = 1; i <= d; ++i){
            for (int j = 1; j <= target; ++j){
                int res = 0;
                for (int k = j - 1; k >= max(0, j - f); --k)
                    res = (res +ff[i - 1][k]) % 1000000007;
                ff[i][j] = res;
            }
        }
        return ff[d][target];
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
