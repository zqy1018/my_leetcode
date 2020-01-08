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
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if ( dungeon.empty() ) return 1;
        int n = dungeon.size(), m = dungeon[0].size();
        for (int i = n - 1; i >= 0; --i)
            for (int j = m - 1; j >= 0; --j){
                if ( i == n - 1 && j == m - 1 )
                    dungeon[i][j] = max( 0, -dungeon[i][j] ) + 1;
                else {
                    int mini = 2147483647;
                    if ( i + 1 < n ) mini = min( mini, dungeon[i + 1][j] );
                    if ( j + 1 < m ) mini = min( mini, dungeon[i][j + 1] );
                    dungeon[i][j] = max( 1, mini - dungeon[i][j] );
                }
            }
        return dungeon[0][0];
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
