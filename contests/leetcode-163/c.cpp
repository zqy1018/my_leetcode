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

int maxi[10];
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        memset(maxi, 0, sizeof(maxi));
        maxi[1] = maxi[2] = -1;
        int tt[10] = {0};
        int n = nums.size();
        for (int i = 0; i < n; ++i){
            int v = nums[i];
            for (int j = 0; j < 3; ++j)
                tt[j] = -1;
            for (int j = 0; j < 3; ++j){
                int bb = (j + v) % 3;
                if (maxi[j] >= 0) tt[bb] = maxi[j] + v;
            }
            if (tt[v % 3] < 0) tt[v % 3] = v;
            for (int j = 0; j < 3; ++j)
                maxi[j] = max(maxi[j], tt[j]);
            cout << tt[0] << " " << tt[1] << " " << tt[2] << endl;
        }
        return maxi[0];
    }
};
Solution sol;
void init(){
    vector<int> vec{3, 6, 5, 1, 8};
    cout << sol.maxSumDivThree(vec);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
