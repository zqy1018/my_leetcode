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

int to[20005], at[10005], nxt[20005], cnt;
int f[10005], d[10005];
int dfs(int cur, int fa){
    int dep = 1;
    int maxi1 = 0, maxi2 = 0;
    for (int i = at[cur]; i; i = nxt[i]){
        int v = to[i];
        if (v == fa) continue ;
        int dd = dfs(v, cur);
        dep = max(dep, dd + 1);
        if (maxi1 < dd)
            maxi2 = maxi1, maxi1 = dd;
        else if (dd > maxi2)
            maxi2 = dd;
    }
    f[cur] = maxi1 + maxi2 + 1;
    d[cur] = dep; 
    return dep;
}
class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        cnt = 0;
        memset(at, 0, sizeof(at));
        memset(f, 0, sizeof(f));
        memset(d, 0, sizeof(d));
        for (vector<int>& vec: edges){
            int u = vec[0] + 1, v = vec[1] + 1;
            to[++cnt] = v, nxt[cnt] = at[u], at[u] = cnt;
            to[++cnt] = u, nxt[cnt] = at[v], at[v] = cnt;
        }
        dfs(1, 0);
        int ans = 0, n = edges.size() + 1;
        for (int i = 1; i <= n; ++i)
            ans = max(ans, f[i]);
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
