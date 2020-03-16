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
    double f[105][55];
    vector<int> G[105];
    void dfs(int cur, int fa, int curt){
        int sz = G[cur].size();
        if (fa != 0) --sz; 
        if (sz == 0){
            f[cur][curt] += f[cur][curt - 1];
            return ;
        }
        for (int x: G[cur]){
            if (x == fa) continue;
            f[x][curt] = 1.0 * f[cur][curt - 1] * (1.0 / sz);
            dfs(x, cur, curt);
        }
    }
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        for (auto& v: edges)
            G[v[0]].push_back(v[1]), G[v[1]].push_back(v[0]);
        f[1][0] = 1;
        for (int i = 1; i <= t; ++i)
            dfs(1, 0, i);
        return f[target][t];
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
