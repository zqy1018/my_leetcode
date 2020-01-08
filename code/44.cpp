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
    bool isMatch(string s, string p) {
		int n = s.length(), m = p.length();
        vector<vector<bool> > f(n + 1, vector<bool>(m + 1, false));
		f[0][0] = true;
		for (int j = 1; j <= m; ++j){
			if (p[j - 1] != '*') break;
			f[0][j] = true;
		}
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= m; ++j){
				if (isalpha(p[j - 1])){
					f[i][j] = (f[i - 1][j - 1] && s[i - 1] == p[j - 1]);
				}else if (p[j - 1] == '?'){
					f[i][j] = f[i - 1][j - 1];
				}else{
					f[i][j] = f[i][j - 1] || f[i - 1][j - 1] || f[i - 1][j];
				}
			}
		}
		return f[n][m];
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
