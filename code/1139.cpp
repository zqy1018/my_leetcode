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
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> sum1(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> sum2(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                sum1[i + 1][j + 1] = sum1[i + 1][j] + grid[i][j],
                sum2[i + 1][j + 1] = sum2[i][j + 1] + grid[i][j];
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j){
                for (int k = min(i, j); k >= 1; --k){
                    if (sum1[i][j] - sum1[i][j - k] == k && 
                        sum1[i - k + 1][j] - sum1[i - k + 1][j - k] == k &&
                        sum2[i][j] - sum2[i - k][j] == k &&
                        sum2[i][j - k + 1] - sum2[i - k][j - k + 1] == k){
                            ans = max(ans, k * k);
                            break;
                    }
                }
            }
        return ans;
    }
};
Solution sol;
void init(){
    vector<vector<int>> vec{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    cout << sol.largest1BorderedSquare(vec);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
