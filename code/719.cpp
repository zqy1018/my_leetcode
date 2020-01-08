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
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back() - nums.front();
        int n = nums.size();
        while (r > l){
            int mid = (l + r) >> 1;
            int cur = 0, cnt = 0;
            for (int i = 1; i < n; ++i){
                while (cur < i && nums[i] - nums[cur] > mid)
                    ++cur;
                cnt += 2 * (i - cur);
            }
            if (cnt < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
Solution sol;
void init(){
    vector<int> vec{1, 1, 3};
    cout << sol.smallestDistancePair(vec, 1);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
