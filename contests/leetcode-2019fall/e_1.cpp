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

int to[50005], nxt[50005], at[50005], cnt;
int dfn[50005], dfn2[50005], D;
int seg[200005], tag[200005], nn;
int _a, _b, _v;
bitset<50005> bs;
void dfs(int cur){
    dfn[cur] = ++D;
    for (int i = at[cur]; i; i = nxt[i])
        dfs(to[i]);
    dfn2[cur] = D;
}
inline int addmod(int a, int b){
    return (a + b >= 1000000007 ? a + b - 1000000007: a + b);
}
void pushdown(int id, int len){
    if (tag[id]){
        int t = 1ll * len * tag[id] % 1000000007;
        seg[id << 1] = addmod(seg[id << 1], t);
        tag[id << 1] = addmod(tag[id << 1], tag[id]);
        seg[id << 1 | 1] = addmod(seg[id << 1 | 1], t);
        tag[id << 1 | 1] = addmod(tag[id << 1 | 1], tag[id]);
        tag[id] = 0;
    }
}
void update(int id, int l, int r){
    if (l > _b || r < _a) return ;
    if (r <= _b && l >= _a){
        int t = 1ll * (r - l + 1) * _v % 1000000007;
        seg[id] = addmod(seg[id], t);
        tag[id] = addmod(tag[id], _v);
        return ;
    }
    pushdown(id, (r - l + 1) >> 1);
    int mid = (l + r) >> 1;
    if (_a <= mid) update(id << 1, l, mid);
    if (_b > mid) update(id << 1 | 1, mid + 1, r); 
    seg[id] = addmod(seg[id << 1], seg[id << 1 | 1]);
}
int query(int id, int l, int r){
    if (l > _b || r < _a) return 0;
    if (r <= _b && l >= _a) return seg[id];
    pushdown(id, (r - l + 1) >> 1);
    int mid = (l + r) >> 1;
    return addmod(query(id << 1, l, mid), query(id << 1 | 1, mid + 1, r));
}
class Solution {
public:
    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
        memset(at, 0, sizeof(at));
        D = cnt = 0;
        memset(seg, 0, sizeof(seg));
        memset(tag, 0, sizeof(tag));
        for (auto& e: leadership){
            int u = e[0], v = e[1];
            to[++cnt] = v, nxt[cnt] = at[u], at[u] = cnt;
            bs.set(v);
        }
        int rt = -1;
        for (int i = 1; i <= n; ++i)    
            if (!bs.test(i)){
                rt = i;
                break;
            }
        dfs(rt);
        
        vector<int> ans;
        for (nn = 1; nn < n; nn <<= 1) ;
        for (auto& q: operations){
            if (q[0] == 1)
                _a = _b = dfn[q[1]], _v = q[2], update(1, 1, nn);
            if (q[0] == 2)
                _a = dfn[q[1]], _b = dfn2[q[1]], _v = q[2], update(1, 1, nn);
            if (q[0] == 3)
                _a = dfn[q[1]], _b = dfn2[q[1]], ans.push_back(query(1, 1, nn));
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
