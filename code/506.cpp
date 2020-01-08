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
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> ans;
        vector<int> id(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i)
            id[i] = i;
        sort(id.begin(), id.end(), [&nums](int x, int y) { return nums[x] > nums[y]; });
        for (int i = 0; i < nums.size(); ++i)   
            nums[id[i]] = i;
        for (int i = 0; i < nums.size(); ++i)  {
            if (nums[i] == 0) ans.push_back("Gold Medal");
            else if (nums[i] == 1) ans.push_back("Silver Medal");
            else if (nums[i] == 2) ans.push_back("Bronze Medal");
            else ans.push_back(to_string(nums[i] + 1));
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
