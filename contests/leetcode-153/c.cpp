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

int maxi[100005], sum[100005];
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size(), ans = INT_MIN;
        sum[0] = 0, maxi[0] = 0;
        for (int i = 1, mini = 0; i <= n; ++i){
            sum[i] = sum[i - 1] + arr[i - 1];
            maxi[i] = sum[i] - mini;
            mini = min(mini, sum[i]);
            ans = max(ans, maxi[i]);
        }
        for (int i = 1, maxx = 0; i <= n; ++i){
            ans = max(ans, sum[i] + maxx);
            maxx = max(maxx, maxi[i - 1] - sum[i]);
        }
        return ans;
    }
};
Solution sol;
void init(){
    vector<int> vec{1, -2, 0, 3};
    cout << sol.maximumSum(vec);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
