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
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int> > qmax(n + 1, vector<int>(n + 1, -1));
        for (int i = 1; i <= n; ++i){
            for (int j = i; j <= n; ++j){
                for (int k = i; k <= j; ++k)
                    qmax[i][j] = max(qmax[i][j], arr[k - 1]);
            }
        }
        vector<vector<int> > f(n + 1, vector<int>(n + 1, 2147483647));
        for (int i = 1; i <= n; ++i)
            f[i][i] = 0;
        for (int i = 1; i < n; ++i){
            for (int j = 1; j + i <= n; ++j){
                for (int k = j; k < j + i; ++k){
                    f[j][j + i] = min(f[j][j + i], f[j][k] + f[k + 1][j + i] + qmax[j][k] * qmax[k + 1][j + i]);
                }
            }
        }
        return f[1][n];
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
