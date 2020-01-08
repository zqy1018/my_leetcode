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
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                sum[i + 1][j + 1] = sum[i][j + 1] + matrix[i][j];
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 1; i <= n; ++i){
            for (int j = i; j <= n; ++j){
                mp.clear();
                mp[0] = 1;
                int ssm = 0;
                for (int k = 1; k <= m; ++k){
                    ssm += sum[j][k] - sum[i - 1][k];
                    if (mp.count(ssm - target)) 
                        ans += mp[ssm - target];
                    if (mp.count(ssm))
                        ++mp[ssm];
                    else mp[ssm] = 1;
                }
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
