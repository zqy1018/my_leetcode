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
    vector<int> to[1005];
    int du[1005], s, t, n, tot;
    bool vis[1005];
    bool dfs(int cur){
        ++tot;
        if (cur == s){
            for (int v: to[cur]){
                if (v == t) continue;           // 这条边已经被删了
                if (!vis[v])
                    vis[v] = true, dfs(v);
                else return false;
            }
        }else {
            for (int v: to[cur]){
                if (!vis[v])
                    vis[v] = true, dfs(v);
                else return false;
            }
        }
        return true;
    }
    bool ok(){
        int rt = -1;
        for (int i = 1; i <= n; ++i)
            if (!du[i]){
                if (rt < 0) rt = i;
                else return false;
            }
        if (rt < 0) return false;
        memset(vis, 0, sizeof(vis));
        tot = 0;
        vis[rt] = true;
        if (!dfs(rt) || tot < n) return false;
        return true;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        for (auto& e: edges)
            to[e[0]].push_back(e[1]), ++du[e[1]];
        n = edges.size();
        for (int i = n - 1; i >= 0; --i){
            s = edges[i][0], t = edges[i][1];
            --du[t];
            if (ok()) return edges[i];
            ++du[t];
        }
        return vector<int>();
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
