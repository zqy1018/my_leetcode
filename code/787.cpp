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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dis(n, 0x3f3f3f3f), dis2(n);
        vector<vector<pair<int, int>>> edges(n, vector<pair<int, int>>());
        for (vector<int>& edge: flights){
            int u = edge[0], v = edge[1], w = edge[2];
            edges[u].push_back(make_pair(v, w));
        }
        dis[src] = 0;
        for (int T = 0; T <= K; ++T){
            for (int i = 0; i < n; ++i)
                dis2[i] = dis[i];
            for (int i = 0; i < n; ++i){
                int siz = edges[i].size();
                for (int j = 0; j < siz; ++j){
                    int v = edges[i][j].first, w = edges[i][j].second;
                    dis[v] = min(dis[v], dis2[i] + w);
                }
            }
        }
        return (dis[dst] == 0x3f3f3f3f ? -1: dis[dst]);
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
