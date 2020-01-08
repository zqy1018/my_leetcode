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
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i)
            mp[nums[i]] = i;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i){
            if ( !mp.count( nums[i] ) ) continue;
            mp.erase( nums[i] );
            int res = 1, tmp = nums[i];
            while ( mp.count( tmp + 1 ) )
                ++res, mp.erase( tmp + 1 ), ++tmp;
            tmp = nums[i];
            while ( mp.count( tmp - 1 ) )
                ++res, mp.erase( tmp - 1 ), --tmp;
            ans = max( ans, res );
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
