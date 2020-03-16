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
    int fa[100005], siz[100005];
    int Find(int x){
        return (x == fa[x]) ? x: (fa[x] = Find(fa[x]));
    }
    void Union(int x, int y){
        if (siz[x] > siz[y])
            fa[y] = x, siz[x] += siz[y];
        else
            fa[x] = y, siz[y] += siz[x];
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        for (int i = 1; i <= n; ++i)
            fa[i] = i, siz[i] = 1;
        int res = n;
        for (auto& p: connections){
            int u = p[0] + 1, v = p[1] + 1;
            if (Find(u) != Find(v))
                --res, Union(Find(u), Find(v));
        }
        return res - 1;
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
