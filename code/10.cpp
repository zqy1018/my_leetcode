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
		int n = s.length(), rm = p.length(), m = rm;
		for (char c: p) if (c == '*') --m;
        vector<vector<bool> > f(n + 1, vector<bool>(m + 1, false));
		f[0][0] = true;
		for (int j = 2; j <= rm; j += 2){
			if (p[j - 1] != '*') break;
			f[0][j >> 1] = true;
		}
		for (int i = 1; i <= n; ++i){
			for (int j = 1, j_ = 1; j <= rm; ++j){
				if (j < rm && p[j] == '*') continue;
				if (isalpha(p[j - 1])){
					f[i][j_] = (f[i - 1][j_ - 1] && s[i - 1] == p[j - 1]);
				}else if (p[j - 1] == '.'){
					f[i][j_] = f[i - 1][j_ - 1];
				}else{
					if (p[j - 2] != '.' && p[j - 2] == s[i - 1]){
						f[i][j_] = f[i][j_ - 1] || f[i - 1][j_ - 1];
						if (i >= 2 && s[i - 1] == s[i - 2])
							f[i][j_] = f[i][j_] || f[i - 1][j_];
					}else if (p[j - 2] == '.') {
						f[i][j_] = f[i][j_ - 1] || f[i - 1][j_ - 1] || f[i - 1][j_];
					}else{
						f[i][j_] = f[i][j_ - 1];
					}
				}
				++j_;
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
