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
int siz[10005], res[10005], n;
class Solution {
public:
    void dfs(int cur, int fa){
        ++siz[cur];
        for (int i = at[cur]; i != -1; i = nxt[i]){
            int v = to[i];
            if (v == fa) continue;
            dfs(v, cur);
            siz[cur] += siz[v], res[cur] += res[v] + siz[v];
        }
    }
    void dfs2(int cur, int fa){
        for (int i = at[cur]; i != -1; i = nxt[i]){
            int v = to[i];
            if (v == fa) continue;
            res[v] = res[cur] - siz[v] + n - siz[v];
            dfs2(v, cur);
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n = N, cnt = 0;
        for (int i = 0; i < N; ++i) at[i] = -1, siz[i] = res[i] = 0;
        for (vector<int>& e: edges){
            int u = e[0], v = e[1];
            to[cnt] = v, nxt[cnt] = at[u], at[u] = cnt++;
            to[cnt] = u, nxt[cnt] = at[v], at[v] = cnt++;
        }
        vector<int> ans(N, 0);
        dfs(1, 0);
        dfs2(1, 0);
        for (int i = 0; i < N; ++i) ans[i] = res[i];
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
