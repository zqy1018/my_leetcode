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

int f[4100][12], dis[12][12];
class Solution {
public:
    inline int lowbit(int x){ return x & (-x); }
    unordered_map<int, int> mp;
    void init(int n){
        memset(f, 0x3f, sizeof(f));
        memset(dis, 0x3f, sizeof(dis));
        for (int i = 0; i < n; ++i)
            mp[1 << i] = i, f[1 << i][i] = 0;
    }
    void dfs(int di, int dj, vector<vector<int>>& graph){
        if (f[di][dj] < 0x3f3f3f3f) return ;
        int dii = di - (1 << dj);
        for (int i = dii, j = lowbit(i); i > 0; i -= j, j = lowbit(i)){
            int id = mp[j];
            dfs(dii, id, graph);
            f[di][dj] = min(f[dii][id] + dis[id][dj], f[di][dj]);
        }
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(); 
        init(n);
        for (int i = 0; i < n; ++i) {
            dis[i][i] = 0;
            for (int v: graph[i])
                dis[i][v] = dis[v][i] = 1;
        }
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i) 
                for (int j = 0; j < n; ++j)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i)
            dfs((1 << n) - 1, i, graph), ans = min(ans, f[(1 << n) - 1][i]);
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
