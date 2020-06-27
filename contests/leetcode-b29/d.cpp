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

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec){
    for (auto x: vec)
        os << x << " ";
    os << endl;
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<vector<T>>& vec){
    for (auto& v: vec){
        for (auto x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}
class Solution {
    int f[40005], du[40005][16];
    vector<int> G[16];
    queue<int> q;
    bool vis[40005];
    int lst[16], cc[16], nn, kk, tot, hh;
    void upd(int cur, int cur2, int pp){
        int lft = kk - cur2;
        if (!lft){
            for (int i = 0; i < nn; ++i)
                du[pp][i] = du[hh][i];
            for (int i = 0; i < kk; ++i){
                for (int t: G[cc[i]])
                    --du[pp][t];
            }
            f[pp] = min(f[pp], f[hh] + 1);
            if (!vis[pp]) vis[pp] = true, q.push(pp);
            return ;
        }
        for (int i = cur; i <= tot - lft; ++i){
            cc[cur2] = lst[i];
            upd(i + 1, cur2 + 1, pp | (1 << lst[i]));
        }
    }
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        for (auto& e: dependencies){
            int u = e[0] - 1, v = e[1] - 1;
            G[u].push_back(v);
            ++du[0][v];
        }
        memset(f, 0x3f, sizeof(f));
        q.push(0);
        f[0] = 0;
        nn = n, kk = k;
        while (!q.empty()){
            int h = q.front();
            q.pop();
            tot = 0;
            for (int i = 0; i < n; ++i)
                if (!du[h][i] && !(h & (1 << i))) lst[tot++] = i;
            if (tot <= k){
                int old_h = h;
                for (int i = 0; i < tot; ++i){
                    h |= (1 << lst[i]);
                }
                for (int i = 0; i < n; ++i)
                    du[h][i] = du[old_h][i];
                for (int i = 0; i < tot; ++i){
                    for (int t: G[lst[i]]){
                        --du[h][t];
                    }
                }
                f[h] = min(f[h], f[old_h] + 1);
                if (!vis[h]) vis[h] =true, q.push(h);
            }else {
                hh = h;
                upd(0, 0, h);
            }
        }
        return f[(1 << n) - 1];
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
