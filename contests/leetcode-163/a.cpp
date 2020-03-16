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
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> t1 = grid, t2 = grid;
        int n = grid.size(), m=grid[0].size();
        for (int T = 0; T < k; ++T) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j){
                    if (j == m - 1){
                        if (i == n - 1) 
                            t2[0][0] = t1[i][j];
                        else 
                            t2[i + 1][0] = t1[i][j];
                    }else {
                        t2[i][j + 1] = t1[i][j];
                    }
                }
            }
            t1 = t2;
        }
        return t1;
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
