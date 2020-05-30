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

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec){
    for (auto x: vec)
        os << x << " ";
    os << endl;
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<vector<T>>& vec){
    for (auto& v: vec){
        for (auto x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}

class Solution {
    int f[105][105][105];
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        memset(f, -1, sizeof(f));
        f[0][0][m - 1] = grid[0][0] + grid[0][m - 1];
        for (int i = 1; i < n; ++i){
            for (int j = 0; j < m; ++j) 
                for (int k = 0; k < m; ++k){
                    if (f[i - 1][j][k] < 0) continue;
                    for (int u = -1; u <= 1; ++u){
                        if (j + u < 0 || j + u >= m) continue;
                        for (int v = -1; v <= 1; ++v){
                            if (k + v < 0 || k + v >= m) continue;
                            f[i][j + u][k + v] = max(f[i][j + u][k + v], f[i - 1][j][k] + 
                                (j + u == k + v ? grid[i][j + u]: 
                                    grid[i][j + u] + grid[i][k + v]));
                        }
                    }
                }
        }
        int ans = -1;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < m; ++j)
                ans = max(ans, f[n - 1][i][j]);
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
