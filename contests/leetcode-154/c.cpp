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

int sum[100005];
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        memset(sum, 0, sizeof(sum));
        int n = arr.size();
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + arr[i - 1];
        int maxi1 = 0, maxi2 = 0;
        int res2 = 0, mini = 0;
        for (int i = 1; i <= n; ++i){
            maxi1 = max(maxi1, sum[i]);
            res2 = max(res2, sum[i] -  mini);
            mini = min(mini, sum[i]);
        }
        sum[n + 1] = 0;
        for (int i = n; i >= 1; --i)
            sum[i] = sum[i + 1] + arr[i - 1];
        for (int i = n; i >= 1; --i)
            maxi2 = max(maxi2, sum[i]);
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + arr[i - 1];
        if (k == 1) return res2;
        if (sum[n] < 0)
            return max(res2, (maxi1 + maxi2) % 1000000007);
        
        int tt = 1ll * (k - 2) * sum[n] % 1000000007;
        tt += (maxi1 + maxi2) % 1000000007;
        cout << maxi1 << " " << maxi2 << endl;
        if (tt >=1000000007) tt-=1000000007;
        return tt;
    }
};
Solution sol;
void init(){
    vector<int> vec{1, 2};
    cout << sol.kConcatenationMaxSum(vec, 3);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
