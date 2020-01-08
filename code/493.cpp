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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> tmp;
    int ans;
    void Merge(vector<int>& nums, int f, int md, int l){
	    int lp = f, rp = md, pos = f;
        int cur = md;
    	while(lp < md && rp < l){
    		if(nums[lp] < nums[rp]) {
                while (cur < l && 1ll * nums[lp] > 2ll * nums[cur])
                    ++cur;
                ans += cur - md, tmp[pos++] = nums[lp++];
            }else tmp[pos++] = nums[rp++];
    	}
    	while(lp < md) {
            while (cur < l && 1ll * nums[lp] > 2ll * nums[cur])
                ++cur;
            ans += cur - md, tmp[pos++] = nums[lp++];
        }
    	while(rp < l) tmp[pos++] = nums[rp++];
        for (int i = f; i < l; ++i) 
            nums[i] = tmp[i];
    }
    void MSort(vector<int>& nums, int l, int r){
    	if(r - l <= 1) return ;
    	else{
            int mid = (l + r) >> 1;
    		MSort(nums, l, mid);
    		MSort(nums, mid, r);
    		Merge(nums, l, mid, r);
    	}
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        tmp = vector<int>(n, 0);
        ans = 0;
        MSort(nums, 0, n);
        return ans;
    }
};
Solution sol;
void init(){
    vector<int> vec{-185,143,-154};
    cout << sol.reversePairs(vec);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
