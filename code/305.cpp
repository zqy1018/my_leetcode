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

ostream& operator << (ostream& os, const vector<int>& vec){
    for (int x: vec)
        os << x << " ";
    os << endl;
    return os;
}

ostream& operator << (ostream& os, const vector<vector<int>>& vec){
    for (auto& v: vec){
        for (int x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}

const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
class Solution {
    int fa[10005], tot;
    int Find(int x){
        return (x == fa[x] ? x: (fa[x] = Find(fa[x])));
    }
    void Union(int x, int y){
        int u = Find(x), v = Find(y);
        if (u == v) return ;
        fa[u] = v, --tot;
    }
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int S = m * n;
        tot = 0;
        vector<int> ans;
        for (auto& p: positions){
            int pos = p[0] * n + p[1] + 1;
            fa[pos] = pos;
            ++tot;
            for (int i = 0; i < 4; ++i){
                int cx = p[0] + dx[i], cy = p[1] + dy[i];
                if (cx < 0 || cy < 0 || cx >= m || cy >= n) 
                    continue;
                int poss = cx * n + cy + 1;
                if (fa[poss]) Union(pos, poss);
            }
            ans.push_back(tot);
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
