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


int to[200005], at[100005], nxt[200005], cnt;
int D, pre[100005]; 
int dfn[100005], low[100005], vis[100005];
bool bridge[200005], used[200005];
void tarjan(int u){
    vis[u] = 1;
    dfn[u] = low[u] = ++D;
    for(int i = at[u]; i; i = nxt[i]){
        if(!used[i]){
            used[i] = true;
            if (i & 1) used[i + 1] = true;
            else used[i - 1] = true;
            int v = to[i];
            if(!vis[v]){
                pre[v] = u, tarjan(v);
                low[u] = min(low[u], low[v]);
                if(dfn[u] < low[v])
                    bridge[v] = true;
            }else if(vis[v] == 1){
                low[u] = min(low[u], dfn[v]);
            }
        }
    }
    vis[u] = 2;
}
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        memset(at, 0, sizeof(at));
        memset(vis, 0, sizeof(vis));
        memset(bridge, 0, sizeof(bridge));        
        memset(used, 0, sizeof(used));  
        memset(pre, 0, sizeof(pre));       
        D = 0, cnt = 0;
        for (vector<int>& e: connections){
            int u = e[0] + 1, v = e[1] + 1;
            to[++cnt] = v, nxt[cnt] = at[u], at[u] = cnt;
            to[++cnt] = u, nxt[cnt] = at[v], at[v] = cnt;
        }
        pre[1] = 1, tarjan(1);
        int E = connections.size();
        
        vector<vector<int>> vec;
        for (int i = 1; i <= n; ++i)
            if (bridge[i])
                vec.push_back(vector<int>{i - 1, pre[i] - 1});
        return vec;
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
