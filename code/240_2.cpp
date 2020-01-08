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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if ( !n ) return false;
        int m = matrix[0].size();
        for (int x = n - 1, y = 0; y < m && x >= 0; ){
            if ( matrix[x][y] == target ) return true;
            else {
                if ( matrix[x][y] < target ) ++y;
                else --x;
            }
        }
        return false;
    }
};
Solution sol;
void init(){
    
}
void solve(){
	vector<vector<int> > ss(1001, vector<int>(1001, 0));
    ss[1][1] = 1;
    for (int i = 1; i <= 1000; ++i)
        for (int j = 1; j <= 1000; ++j)
            ss[i][j] = 3 * ss[i >> 1][j >> 1] + 1;
    cout << ss[1000][1000] << endl;
}
int main(){
	init();
	solve();
	return 0;
}
