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

bool vis[305];
class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        queue<int> q;
        int n = graph.size(), ans = n + 1, p = -1;
        for (int removed: initial){
            memset(vis, 0, sizeof(vis));
            int injected = 0;
            for (int x: initial)
                if (x != removed) q.push(x), vis[x] = true, ++injected;
            while (!q.empty()){
                int h = q.front();
                q.pop();
                for (int i = 0; i < n; ++i)
                    if (graph[h][i] && !vis[i])
                        vis[i] = true, q.push(i), ++injected;
            }
            if (injected < ans)
                p = removed, ans = injected;
            else if (injected == ans)
                p = min(p, removed);
        }
        return p;
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
