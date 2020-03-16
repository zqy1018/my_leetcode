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
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int ans = 0;
        for (int k = 0; k < 8; k++){
            int res1 = -0x3f3f3f3f;
            int res2 = 0x3f3f3f3f;
            for (int i = 0; i < n; i++){
                int tmp = 0;
                tmp += arr1[i] * (((k >> 0) & 1) * 2 - 1);
                tmp += arr2[i] * (((k >> 1) & 1) * 2 - 1);
                tmp += i * (((k >> 2) & 1) * 2 - 1);
                res1 = max(res1, tmp);
                res2 = min(res2, tmp);
            }
            ans = max(ans, res1 - res2);
        }
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
