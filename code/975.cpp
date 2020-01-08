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

int bef[100005], aft[100005];
int at[100005], to[100005], nxt[100005], cnt;
int at2[20005], to2[40005], nxt2[40005], cnt2;
bool w[40005];
bool vis[20005][2];
class Solution {
public:
    void dfs(int cur, int b){
        for (int i = at2[cur]; i; i = nxt2[i]){
            if (w[i] != b) continue;
            int v = to2[i];
            if (vis[v][b]) continue;
            vis[v][b] = true;
            dfs(v, b ^ 1);
        }
    }
    int oddEvenJumps(vector<int>& A) {
        cnt = cnt2 = 0;
        memset(at, 0, sizeof(at));
        memset(at2, 0, sizeof(at2));
        memset(vis, 0, sizeof(vis));
        int n = A.size(), maxi = 0;
        for (int i = n - 1; i >= 0; --i){
            maxi = max(maxi, A[i] + 1);
            to[++cnt] = i + 1, nxt[cnt] = at[A[i] + 1], at[A[i] + 1] = cnt;
        }
        int lst = 0;
        for (int i = 1; i <= maxi; ++i){
            if (!at[i]) continue;
            if (lst) 
                bef[i] = lst, aft[lst] = i;
            else bef[i] = 0;
            lst = i;
        }
        nxt[lst] = 0;
        for (int i = 0; i < n; ++i){
            int v = A[i] + 1;
            at[v] = nxt[at[v]];         // 删除自己
            if (at[v]){
                int vv = to[at[v]];
                to2[++cnt2] = i + 1, w[cnt2] = 1, nxt2[cnt2] = at2[vv], at2[vv] = cnt2;
                to2[++cnt2] = i + 1, w[cnt2] = 0, nxt2[cnt2] = at2[vv], at2[vv] = cnt2;
            }else {
                if (aft[v] && at[aft[v]]){
                    int vv = to[at[aft[v]]];
                    to2[++cnt2] = i + 1, w[cnt2] = 1, nxt2[cnt2] = at2[vv], at2[vv] = cnt2;
                    bef[aft[v]] = bef[v];
                }
                if (bef[v] && at[bef[v]]){
                    int vv = to[at[bef[v]]];
                    to2[++cnt2] = i + 1, w[cnt2] = 0, nxt2[cnt2] = at2[vv], at2[vv] = cnt2;
                    aft[bef[v]] = aft[v];
                }
            }
        }
        /*for (int i = 1; i <= cnt2; ++i)
            cout << to2[i] << " " << nxt2[i] << " " << w[i] << endl;
        for (int i = 1; i <= n; ++i)
            cout << at2[i] << endl;*/
        int ans = 0;
        dfs(n, 1), dfs(n, 0);
        for (int i = 1; i < n; ++i) 
            if (vis[i][1])
                ++ans;
        return ans + 1;
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
