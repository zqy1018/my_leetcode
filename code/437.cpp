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
    int targ, ans;
    unordered_map<int, int> mp;
    void dfs(TreeNode* root, int cur){
        cur += root->val;
        if(mp.count(cur - targ))
            ans += mp[cur - targ];
        if(mp.count(cur)) mp[cur]++;
        else mp[cur] = 1;
        if(root->left != NULL) dfs(root->left, cur);
        if(root->right != NULL) dfs(root->right, cur);
        mp[cur]--;
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) return 0;
        ans = 0, targ = sum;
        mp[0] = 1;
        dfs(root, 0);
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
