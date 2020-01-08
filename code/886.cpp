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

int to[20005], nxt[20005], at[2005], cnt;
int col[2005];
class Solution {
public:
    bool dfs(int cur, int c){
        if (!col[cur])
            col[cur] = c;
        else if (col[cur] != c)
            return false;
        else return true;
        for (int i = at[cur]; i; i = nxt[i])    
            if (!dfs(to[i], 3 - c))
                return false;
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        memset(at, 0, sizeof(at));
        memset(col, 0, sizeof(col));
        cnt = 0;
        for (vector<int>& e: dislikes){
            int u = e[0], v = e[1];
            to[++cnt] = v, nxt[cnt] = at[u], at[u] = cnt;
            to[++cnt] = u, nxt[cnt] = at[v], at[v] = cnt;
        }
        for (int i = 1; i <= N; ++i)
            if (!col[i] && !dfs(i, 1))
                return false;
        return true;
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
