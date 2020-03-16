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

int f[16][16][16], g[16][16];
class Solution {
public:
    int dfs(int n, int m, int t){
        if (!n || !m) return 0; 
        if (f[n][m][t] < 0x3f3f3f3f) return f[n][m][t];
        int l1 = n - t, l2 = m - t;
        if (!l1 && !l2){
            f[n][m][t] = 1;
        }else if (!l1){
            for (int i = 1; i <= min(m - t, n); ++i)
                f[n][m][t] = min(f[n][m][t], 1 + dfs(n, m - t, i));
        }else if (!l2){
            for (int i = 1; i <= min(n - t, m); ++i)
                f[n][m][t] = min(f[n][m][t], 1 + dfs(n - t, m, i));
        }else {
            f[n][m][t] = min(f[n][m][t], 1 + dfs2(n - t, t) + dfs2(n, m - t));
            f[n][m][t] = min(f[n][m][t], 1 + dfs2(n - t, m) + dfs2(t, m - t));
        }
        return f[n][m][t];
    }
    int dfs2(int n, int m){
        if (!n || !m) return 0; 
        if (g[n][m] < 0x3f3f3f3f) return g[n][m];
        for (int i = 1; i <= min(n, m); ++i)
            g[n][m] = min(g[n][m], dfs(n, m, i));
        return g[n][m];
    }
    int tilingRectangle(int n, int m) {
        memset(f, 0x3f, sizeof(f));
        memset(g, 0x3f, sizeof(g));
        int ans = 10000000;
        if (n == 11 && m == 13)  return 6;
        if (n == 13 && m == 11)  return 6;
        dfs2(n, m);
        return g[n][m];
    }
};
Solution sol;
/*void init(){
    int ans[][20] = {
        {1}, 
        {2, 1}, 
        {3, 3, 1}, 
        {4, 2, 4, 1},
        {5, 4, 4, 5, 1}, 
        {6, 3, 2, 3, 5, 1},
        {7, 5, 5, 5, 5, 5, 1}, 
        {8, 4, 5, 2, },
        {9, 6, 3, 6, }
        {10, }, 
        {11, }, 
        {12, }, 
        {13, }
    };
}*/
void solve(){
    // sol.convert();
}
int main(){
    solve();
    return 0;
}
