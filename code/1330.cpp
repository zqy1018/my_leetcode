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

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec){
    for (auto x: vec)
        os << x << " ";
    os << endl;
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<vector<T>>& vec){
    for (auto& v: vec){
        for (auto x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}

class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, sum = 0;
        for (int i = 0; i < n - 1; ++i)
            sum += abs(nums[i] - nums[i + 1]), 
            ans = sum;
        for (int i = 1; i < n - 1; ++i)
            ans = max(ans, sum - abs(nums[i] - nums[i + 1]) + abs(nums[0] - nums[i + 1])), 
            ans = max(ans, sum - abs(nums[i] - nums[i + 1]) + abs(nums[n - 1] - nums[i]));
        for (int u = -1; u <= 1; u += 2)
            for (int v = -1; v <= 1; v += 2)
                for (int i = 2, mini = INT_MAX; i < n - 1; ++i)
                    mini = min(mini, u * nums[i - 2] + v * nums[i - 1] + abs(nums[i - 2] - nums[i - 1])), 
                    ans = max(ans, sum + u * nums[i] + v * nums[i + 1] - abs(nums[i] - nums[i + 1]) - mini);
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
