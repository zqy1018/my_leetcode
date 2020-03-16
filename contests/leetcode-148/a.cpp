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
    int movesToMakeZigzag(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int ans = 2147483647, cnt = 0;
        for (int i = 0; i < nums.size(); i += 2){
            if (i == 0) {
                cnt += max(0, nums[1] + 1 - nums[0]);
            }else if (i == nums.size() - 1){
                cnt += max(0, nums[nums.size() - 2] + 1 - nums[nums.size() - 1]);
            }else {
                cnt += max(0, max(nums[i - 1] + 1, nums[i + 1] + 1) - nums[i]);
            }
        }
        ans = min(ans, cnt), cnt = 0;
        for (int i = 0; i < nums.size(); i += 2){
            if (i == 0) {
                cnt += max(0, nums[0] - nums[1] + 1);
            }else if (i == nums.size() - 1){
                cnt += max(0, -nums[nums.size() - 2] + 1 + nums[nums.size() - 1]);
            }else {
                cnt += max(0, nums[i] - min(nums[i - 1] - 1, nums[i + 1] - 1));
            }
        }
        ans = min(ans, cnt), cnt = 0;
        for (int i = 1; i < nums.size(); i += 2){
            if (i == nums.size() - 1){
                cnt += max(0, nums[nums.size() - 2] + 1 - nums[nums.size() - 1]);
            }else {
                cnt += max(0, max(nums[i - 1] + 1, nums[i + 1] + 1) - nums[i]);
            }
        }
        ans = min(ans, cnt), cnt = 0;
        for (int i = 1; i < nums.size(); i += 2){
            if (i == nums.size() - 1){
                cnt += max(0, -nums[nums.size() - 2] + 1 + nums[nums.size() - 1]);
            }else {
                cnt += max(0, nums[i] - min(nums[i - 1] - 1, nums[i + 1] - 1));
            }
        }
        ans = min(ans, cnt);
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
