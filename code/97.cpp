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
    bool isInterleave(string s1, string s2, string s3) {
        if ( s1.empty() ) return s2 == s3;
        if ( s2.empty() ) return s1 == s3;
        int n = s1.length(), m = s2.length();
        if ( n + m != s3.length() ) return false;
        vector<vector<bool> > f( n + 1, vector<bool>( m + 1, false ));
        f[0][0] = true;
        for (int i = 0; i < n; ++i){
            if ( s1[i] == s3[i] && f[i][0] ) f[i + 1][0] = true;
            else break;
        }
        for (int i = 0; i < m; ++i){
            if ( s2[i] == s3[i] && f[0][i] ) f[0][i + 1] = true;
            else break;
        }
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if ( s1[i] == s3[i + j + 1] && f[i][j + 1] )
                    f[i + 1][j + 1] = true;
                else if ( s2[j] == s3[i + j + 1] && f[i + 1][j] ) 
                    f[i + 1][j + 1] = true;
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
