
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

int sum[10005];
class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        sum[0] = 0;
        int n = sweetness.size(), mini = 100000000;
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + sweetness[i - 1], mini = min(mini, sweetness[i - 1]);
        int l = mini, r = sum[n];
        while (r > l){
            int mid = (l + r + 1) >> 1;
            int cnt = 0;
            for (int i = 0; i < n; ){
                int j = i;
                while (j < n && sum[j + 1] - sum[i] < mid)
                    ++j;
                if (j == n) 
                    break;
                ++cnt;
                i = j + 1;
            }
            if (cnt >= K + 1) l = mid;
            else r = mid - 1;
        }
        return l;
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
