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

int to[10005], at[10005], nxt[10005], cnt;
class Solution {
public:
    pair<int, int> dfs(int cur, vector<int>& value){
        int siz = 1, vv = value[cur - 1];
        for (int i = at[cur]; i; i = nxt[i]){
            int v = to[i];
            auto pp = dfs(v, value);
            if (pp.second != 0)
                siz += pp.first, vv += pp.second;
        }
        return make_pair(siz, vv);
    }
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        cnt = 0;
        memset(at, 0, sizeof(at));
        int n = parent.size(), rt = -1;
        for (int i = 0; i < n; ++i){
            if (parent[i] == -1) rt = i + 1;
            else to[++cnt] = i + 1, nxt[cnt] = at[parent[i] + 1], at[parent[i] + 1] = cnt;
        }
        pair<int, int> pp = dfs(rt, value);
        if (pp.second == 0) return 0;
        return pp.first;
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
