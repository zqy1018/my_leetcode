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
    bool bs ( vector<vector<int> >& mat, int l1, int l2, int r1, int r2, int targ ){
        if ( l1 == l2 || r1 == r2 ) return false;
        if ( r2 - r1 == 1 ) {
            --l2;
            while ( l2 > l1 ){
                int mid = ( l1 + l2 ) >> 1;
                if ( targ > mat[mid][r1] )
                    l1 = mid + 1;
                else l2 = mid;
            }
            return mat[l1][r1] == targ;
        }
        if ( l2 - l1 == 1 ) {
            --r2;
            while ( r2 > r1 ){
                int mid = ( r1 + r2 ) >> 1;
                if ( targ > mat[l1][mid] )
                    r1 = mid + 1;
                else r2 = mid;
            }
            return mat[l1][r1] == targ;
        }
        int mid1 = ( l1 + l2 ) >> 1, mid2 = ( r1 + r2 ) >> 1;
        if ( targ <= mat[mid1 - 1][mid2 - 1] ) 
            return bs ( mat, l1, mid1, r1, mid2, targ ) || bs ( mat, mid1, l2, r1, mid2, targ ) 
                || bs ( mat, l1, mid1, mid2, r2, targ );
        else 
            return bs ( mat, mid1, l2, mid2, r2, targ ) || bs ( mat, mid1, l2, r1, mid2, targ ) 
                || bs ( mat, l1, mid1, mid2, r2, targ );
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if ( !n ) return false;
        int m = matrix[0].size();
        return bs( matrix, 0, n, 0, m, target );
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
