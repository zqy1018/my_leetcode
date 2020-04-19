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
    int to[20005], id[20005], w[20005], nxt[20005], at[3006], cnt;
    int d[3005], l1[10005], l2[10005];
    priority_queue<pair<int, int> > pq;
    void dijkstra(int V, int S){
        memset(d, 0x3f, sizeof(d));
        pq.push(make_pair(0, S));
        d[S] = 0;
        for(int i = 0; i < V; ++i){
            while (!pq.empty()){
                if (-pq.top().first > d[pq.top().second])
                    pq.pop();
                else break;
            }
            int minp = pq.top().second, mind = d[minp];
            pq.pop();
            for (int j = at[minp]; j; j = nxt[j])
                if (d[to[j]] > mind + w[j])
                    d[to[j]] = mind + w[j], 
                    pq.push(make_pair(-d[to[j]], to[j]));
        }
    }
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
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
