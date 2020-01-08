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


int at[1000005], to[250005], nxt[250005], cnt;
int dis[1000005];
int que[250005], hd, tl;
bool vis[505];
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        cnt = 0;
        for (auto& rt: routes)  
            for (int x: rt)
                at[x + 1] = 0, dis[x + 1] = 0x3f3f3f3f;
        int n = routes.size();
        for (int i = 0; i < n; ++i)  
            for (int x: routes[i])
                to[++cnt] = i, nxt[cnt] = at[x + 1], at[x + 1] = cnt;
        ++S, ++T;
        dis[S] = 0;
        hd = tl = 0;
        que[tl++] = S;
        memset(vis, 0, sizeof(vis));
        while (tl > hd){
            int u = que[hd++];
            if (u == T) return dis[u];
            for (int i = at[u]; i; i = nxt[i]){
                int rt_id = to[i];
                if (vis[rt_id]) continue;
                vis[rt_id] = true;
                for (int v: routes[rt_id])
                    if (dis[v + 1] > dis[u] + 1){
                        dis[v + 1] = dis[u] + 1;
                        que[tl++] = v + 1;
                    }
            }
        }
        if (dis[T] >= 0x3f3f3f3f)
            return -1;
        return dis[T];
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
