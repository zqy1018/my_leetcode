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

int mini[270005];
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n = nums.size(), siz;
        for (siz = 1; siz < 100000; siz <<= 1) ;
        for (int i = siz; i < (siz << 1); ++i)
            mini[i] = 100001;
        for (int i = siz - 1; i >= 1; --i)  
            mini[i] = min(mini[i << 1], mini[i << 1 | 1]);
        int kd = 0, maxi = -1;
        int ans = 1;
        for (int i = 0; i < n; ++i){
            int id = nums[i] + siz - 1;
            if (mini[id] == 100001) 
                mini[id] = 1, ++kd;
            else ++mini[id];
            maxi = max(maxi, mini[id]);
            while (id > 1)
                id >>= 1, mini[id] = min(mini[id << 1], mini[id << 1 | 1]);
            if ((mini[1] == 1 && i == 1ll * maxi * (kd - 1)) ||
                (i + 1ll == maxi + 1ll * mini[1] * (kd - 1) && mini[1] + 1 == maxi)){
                ans = max(ans, i + 1);
            }  
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
