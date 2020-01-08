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

int f[105][55][55];
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(f, 0x90, sizeof(f));
        int n = grid.size(), m = grid[0].size();
        f[0][0][0] = grid[0][0];
        for (int k = 1; k < n + m - 1; ++k){
            int lim = min(m - 1, k);
            for (int i = max(0, k - n + 1); i <= lim; ++i){
                int x1 = k - i;
                for (int j = i; j <= lim; ++j){
                    int x2 = k - j;
                    if (grid[x1][i] < 0 || grid[x2][j] < 0)
                        continue;
                    int ff = (x1 == x2 ? grid[x1][i]: grid[x1][i] + grid[x2][j]);

                    bool t1 = (x1 > 0 && grid[x1 - 1][i] >= 0), 
                        t2 = (i > 0 && grid[x1][i - 1] >= 0), 
                        t3 = (x2 > 0 && grid[x2 - 1][j] >= 0), 
                        t4 = (j > 0 && grid[x2][j -  1] >= 0);
                    if (t1 && t3) 
                        f[k][i][j] = max(f[k][i][j], f[k - 1][i][j] + ff);
                    if (t1 && t4) 
                        f[k][i][j] = max(f[k][i][j], f[k - 1][i][j - 1] + ff);
                    if (t2 && t3) 
                        f[k][i][j] = max(f[k][i][j], f[k - 1][i - 1][j] + ff);
                    if (t2 && t4) 
                        f[k][i][j] = max(f[k][i][j], f[k - 1][i - 1][j - 1] + ff);
                }
            }
        }
        return max(f[n + m - 2][m - 1][m - 1], 0);
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
