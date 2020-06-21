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
    pair<int, pair<int, int> > pp[205], p[205];
    int fa[105], m;
    int Find(int x){
        return (x == fa[x] ? x: (fa[x] = Find(fa[x])));
    }
    bool Union(int x, int y){
        int u = Find(x), v = Find(y);
        if (u == v) return false;
        fa[u] = v;
        return true;
    }
    int kruskal(int x, int n){
        int cnt = n, cost = 0;
        int tot = 0;
        for (int i = 0; i < m; ++i){
            if (i != x) p[tot++] = pp[i];
        }
        for (int i = 0; i < n; ++i)
            fa[i] = i;
        sort(p, p + tot);
        for (int i = 0; i < tot; ++i){
            if (Union(p[i].second.first, p[i].second.second))
                --cnt, cost += p[i].first;
        }
        return cnt == 1 ? cost: INT_MAX;
    }
    int kruskal2(int x, int n){
        int cnt = n, cost = 0;
        int tot = 0;
        for (int i = 0; i < n; ++i)
            fa[i] = i;
        for (int i = 0; i < m; ++i){
            if (i != x) p[tot++] = pp[i];
            else cost += pp[i].first, Union(pp[i].second.first, pp[i].second.second), --cnt;
        }
        sort(p, p + tot);
        for (int i = 0; i < tot; ++i){
            if (Union(p[i].second.first, p[i].second.second))
                --cnt, cost += p[i].first;
        }
        return cnt == 1 ? cost: INT_MAX;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> key, nkey;
        m = edges.size();
        for (int i = 0; i < m; ++i){
            pp[i].first = edges[i][2], 
            pp[i].second.first = edges[i][0], 
            pp[i].second.second = edges[i][1];
        }
        int res = kruskal(-1, n);
        for (int i = 0; i < m; ++i){
            if (kruskal(i, n) != res) key.push_back(i);
            else if (kruskal2(i, n) == res) key.push_back(i);
        }
        vector<vector<int> > vec;
        vec.push_back(key);
        vec.push_back(nkey);
        return vec;
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
