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
    int minSwap(vector<int>& A, vector<int>& B) {
        int f0 = 0, f1 = 1;
        for (int i = 1; i < A.size(); ++i){
            int f0_0 = 0x3f3f3f3f, f1_0 = 0x3f3f3f3f;
            if (A[i - 1] < A[i] && B[i - 1] < B[i])
                f0_0 = f0, f1_0 = f1 + 1;
            if (B[i - 1] < A[i] && A[i - 1] < B[i])
                f0_0 = min(f0_0, f1), f1_0 = min(f1_0, f0 + 1);
            f0 = f0_0, f1 = f1_0;
        }
        return min(f0, f1);
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
