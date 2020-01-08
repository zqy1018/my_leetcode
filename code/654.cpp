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
class Solution {
public:
    TreeNode* build(int l, int r, vector<int>& nums){
        if(l > r) return NULL;
        int maxi = -2147483648, pos = -1;
        for (int i = l; i <= r; ++i)
            if(nums[i] > maxi) maxi = nums[i], pos = i;
        TreeNode *root = new TreeNode(maxi);
        root->left = build(l, pos - 1, nums);
        root->right = build(pos + 1, r, nums);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(0, nums.size() - 1, nums);
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
