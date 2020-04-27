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
    int f[100005];
    deque<int> dq;
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int ans = INT_MIN;
        for (int x: nums) ans = max(ans, x);
        int n = nums.size();
        f[0] = 0;
        dq.push_back(0);
        for (int i = 1; i <= n; ++i){
            if (!dq.empty() && dq.front() < k - i)
                dq.pop_front(); 
            f[i] = nums[i - 1] + f[dq.front()];
            ans = max(ans, f[i]);
            while (!dq.empty() && f[i] >= f[dq.back()])
                dq.pop_back();
            dq.push_back(i); 
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
