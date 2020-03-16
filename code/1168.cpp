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
    int fa[10005], id[10005];
    int Find(int x){
        return (fa[x] == x ? x: (fa[x] = Find(fa[x])));
    }
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        int ans = 0, m = pipes.size();
        for (int i = 1; i <= n; ++i)
            fa[i] = i, ans += wells[i - 1];
        for (int i = 0; i < m; ++i)
            id[i] = i;
        sort(id, id + m, [&pipes](int i, int j){
            return pipes[i][2] < pipes[j][2];
        });
        for (int i = 0; i < m; ++i){
            int w = pipes[id[i]][2];
            int uu = Find(pipes[id[i]][0]), vv = Find(pipes[id[i]][1]);
            if (uu == vv) continue;
            if (w < max(wells[uu - 1], wells[vv - 1])){
                ans -= max(wells[uu - 1], wells[vv - 1]);
                ans += w;
                if (wells[uu - 1] > wells[vv - 1]) fa[uu] = vv;
                else fa[vv] = uu;
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
