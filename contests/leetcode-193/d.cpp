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

class TreeAncestor {
    int fa[100005][21];
public:
    TreeAncestor(int n, vector<int>& parent) {
        for (int i = 0; i < n; ++i)
            fa[i][0] = parent[i];
        for (int j = 1; j <= 20; ++j){
            for (int i = 0; i < n; ++i){
                int ffa = fa[i][j - 1];
                if (ffa < 0) fa[i][j] = -1;
                else fa[i][j] = fa[ffa][j - 1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if (node < 0) return -1;
        for (int j = 20; j >= 0; --j){
            int p = (1 << j);
            if (k >= p) {
                k -= p, node = fa[node][j];
            }
            if (node < 0) return -1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
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
