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
    vector<int> G[100005];
    int f[100005];
    void dfs(int cur, int fa,  vector<bool>& hasApple){
        int sm = 0;
        for (int x: G[cur]){
            if (x == fa) continue;
            dfs(x, cur, hasApple);
            if (f[x] >= 0)
                sm += 2 + f[x];
        }
        if (sm == 0 && !hasApple[cur]) f[cur] = -1;
        else f[cur] = sm;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for (auto& v: edges){
            G[v[0]].push_back(v[1]);
            G[v[1]].push_back(v[0]);
        }
        dfs(0, -1, hasApple);
        return max(f[0], 0);
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
