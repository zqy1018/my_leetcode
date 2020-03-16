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
    int sum[10005];
    double findMaxAverage(vector<int>& nums, int k) {
        double l = -10000, r = 10000;
        int n = nums.size();
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + nums[i - 1];
        while (r - l > 1e-6){
            double mid = (l + r) * 0.5;
            double mini = 1e9;
            bool flag = false;
            for (int i = k; i <= n; ++i){
                mini = min(mini, sum[i - k] - mid * (i - k));
                if (sum[i] - mid * i >= mini){
                    flag = true; 
                    break;
                }
            }
            if (flag) l = mid;
            else r = mid;
        } 
        return l;
    }
};
Solution sol;
void init(){
    vector<int> vec{1,12,-5,-6,50,3};
    cout << sol.findMaxAverage(vec, 4) << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
