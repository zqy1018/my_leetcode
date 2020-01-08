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
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> ans = M;
        int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
        int n = M.size(), m = M[0].size();
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                int res = 0, cnt = 0;
                for (int d = 0; d < 9; ++d){
                    int x = i + dx[d], y = j + dy[d];
                    if (x < 0 || y < 0 || x >= n || y >= m) 
                        continue;
                    ++cnt, res += M[x][y];
                }
                ans[i][j] = res / cnt;
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
