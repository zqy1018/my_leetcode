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
const int M = 1000000007;
class Solution {
    int two[100005];
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        two[0] = 1;
        for (int i = 1; i <= n; ++i)
            two[i] = 2ll * two[i - 1]% M;
        for (int i = 0; i < n; ++i){
            if (nums[i] > target) continue;
            int pos = upper_bound(nums.begin(), nums.end(), target - nums[i]) - nums.begin();
            --pos;
            pos = min(pos, i);
            if (pos == i) {
                ans = (ans + two[i]) % M;
            }else if (pos >= 0) {
                int tt = i - pos - 1;
                int res = two[tt];
                res = 1ll * res * ((two[pos + 1] + M - 1) % M) % M;
                ans = (ans + res) % M;
            }
            cout << pos << endl;
            cout << ans << endl;
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
