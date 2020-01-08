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
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 1; i + j < n && j < m; ++j)
                if (matrix[i + j][j] != matrix[i + j - 1][j - 1])
                    return false;
        for (int i = 1; i < m; ++i)
            for (int j = 1; i + j < m && j < n; ++j)
                if (matrix[j][j + i] != matrix[j - 1][i + j - 1])
                    return false;   
        return true; 
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
