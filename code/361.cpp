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

ostream& operator << (ostream& os, const vector<int>& vec){
    for (int x: vec)
        os << x << " ";
    os << endl;
}

ostream& operator << (ostream& os, const vector<vector<int>>& vec){
    for (auto& v: vec){
        for (int x: v)
            os << x << " ";
        os << endl;
    }
}

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        if (!n) return ans;
        int m = grid[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == '0'){
                    int cnt = 0;
                    for (int t = i - 1; t >= 0 && grid[t][j] != 'W'; --t)
                        if (grid[t][j] == 'E') ++cnt;
                    for (int t = i + 1; t < n && grid[t][j] != 'W'; ++t)
                        if (grid[t][j] == 'E') ++cnt;
                    for (int t = j - 1; t >= 0 && grid[i][t] != 'W'; --t)
                        if (grid[i][t] == 'E') ++cnt;
                    for (int t = j + 1; t < m && grid[i][t] != 'W'; ++t)
                        if (grid[i][t] == 'E') ++cnt;
                    ans = max(ans, cnt);
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
