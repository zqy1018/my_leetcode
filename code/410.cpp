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
    int splitArray(vector<int>& nums, int m) {
        unsigned int l = *max_element(nums.begin(), nums.end()), 
            r = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        while (r > l){
            unsigned int mid = (l + r) >> 1;
            int left = m;
            for (int i = 0; i < n; ){
                unsigned int cnt = 0;
                int j = i;
                while (j < n && cnt <= mid)
                    cnt += nums[j++];
                --left;
                i = (cnt > mid ? j - 1: j);
            }
            if (left < 0) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
Solution sol;
void init(){
    vector<int> nums{1, 2147483646};
    cout << sol.splitArray(nums, 1);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
