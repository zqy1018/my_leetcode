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

int to[20005], id[20005], w[20005], nxt[20005], at[3006], cnt;
int d[3005], l1[10005], l2[10005];
bool vis[3005];
void dijkstra(int V, int S){
    d[S] = 0;
    for(int i = 0; i < V; ++i){
        int mind = 2000000000, minp = -1;
        for(int j = 1; j <= V; ++j)
            if(mind > d[j] && !vis[j])
                mind = d[j], minp = j;//寻找当前扩展点
        vis[i] = true;
        for(int j = at[minp]; j; j = nxt[j])
            d[to[j]] = min(d[to[j]], d[minp] + w[j]);//松弛
    }
}
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        memset(at, 0, sizeof(at));
        memset(l1, 0, sizeof(l1));
        memset(l2, 0, sizeof(l2));
        memset(to, 0, sizeof(to));
        memset(id, 0, sizeof(id));
        memset(w, 0, sizeof(w));
        memset(nxt, 0, sizeof(nxt));
        memset(d, 0x3f, sizeof(d));
        memset(vis, 0, sizeof(vis));
        cnt = 0;
        int E = edges.size();
        for (int i = 0; i < E; ++i){
            int u = edges[i][0] + 1, v = edges[i][1] + 1;
            to[++cnt] = v, id[cnt] = i, w[cnt] = edges[i][2] + 1, nxt[cnt] = at[u], at[u] = cnt;
            to[++cnt] = u, id[cnt] = i, w[cnt] = edges[i][2] + 1, nxt[cnt] = at[v], at[v] = cnt;
        }
        dijkstra(N, 1);
        int ans = 0;
        for (int i = 1; i <= N; ++i){
            if (d[i] > M) continue;
            ++ans;
            for (int j = at[i]; j; j = nxt[j]){
                if (i - 1 == edges[id[j]][0])
                    l1[id[j]] = min(M - d[i], edges[id[j]][2]);
                else 
                    l2[id[j]] = min(M - d[i], edges[id[j]][2]);
            }
        }
        for (int i = 0; i < E; ++i)
            ans += min(edges[i][2], l1[i] + l2[i]);
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
