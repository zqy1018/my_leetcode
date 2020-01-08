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


int to[125005], at[505], nxt[125005], cnt;
int du[505];
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        memset(at, 0, sizeof(at));
        memset(du, 0, sizeof(du));
        cnt = 0;
        for (vector<int>& e: richer){
            int u = e[0], v = e[1];
            to[++cnt] = v, nxt[cnt] = at[u], at[u] = cnt;
            to[++cnt] = u, nxt[cnt] = at[v], at[v] = cnt;
            ++du[v];
        }
        int n = quiet.size();
        vector<int> ans(n);
        queue<int> que;
        for (int i = 0; i < n; ++i){
            ans[i] = i;
            if (!du[i]) 
                que.push(i);
        }
        while (!que.empty()){
            int cur = que.front();
            que.pop();
            for (int i = at[cur]; i; i = nxt[i]){
                int v = to[i];
                --du[v];
                if (quiet[ans[v]] > quiet[ans[cur]]) 
                    ans[v] = ans[cur];
                if (!du[v]) que.push(v);
            }
        }
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
