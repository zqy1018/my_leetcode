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

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<int> > f(m + 2, vector<int>(n + 2, 0));
        f[++i][++j] = 1;
        for  (int k = 0; k < N; ++k){
            for (int u = 1; u <= m; ++u){
                for (int v = 1; v <= n; ++v){
                    int dis = abs(i - u) + abs(j - v);
                    if (dis > k || ((k - dis) & 1)) continue;
                    f[u - 1][v] += f[u][v];
                    if (f[u - 1][v] >= 1000000007) f[u - 1][v] %= 1000000007;
                    f[u + 1][v] += f[u][v];
                    if (f[u + 1][v] >= 1000000007) f[u + 1][v] %= 1000000007;
                    f[u][v - 1] += f[u][v];
                    if (f[u][v - 1] >= 1000000007) f[u][v - 1] %= 1000000007;
                    f[u][v + 1] += f[u][v];
                    if (f[u][v + 1] >= 1000000007) f[u][v + 1] %= 1000000007;
                    f[u][v] = 0;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) ans = (ans + f[0][i]) % 1000000007;
        for (int i = 1; i <= m; ++i) ans = (ans + f[i][n + 1]) % 1000000007;
        for (int i = 1; i <= n; ++i) ans = (ans + f[m + 1][i]) % 1000000007;
        for (int i = 1; i <= m; ++i) ans = (ans + f[i][0]) % 1000000007;
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
