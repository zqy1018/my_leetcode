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

int f[2005][2005], g[2005], lb[2005];
int mini[2005];
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int n = arr1.size(), m = arr2.size();
        m = unique(arr2.begin(), arr2.end()) - arr2.begin();
        while (arr2.size() > m)
            arr2.pop_back();
        memset(f, 0x3f, sizeof(f));
        memset(g, 0x3f, sizeof(g));
        memset(mini, 0, sizeof(mini));
        mini[0] = 0x3f3f3f3f;
        g[0] = 0;
        for (int i = 0; i < n; ++i) 
            lb[i + 1] = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
        for (int j = 1; j <= m; ++j)
            f[0][j] = 0;
        for (int i = 1; i <= n; ++i){
            int mmini = 0x3f3f3f3f;
            for (int j = 1; j <= m; ++j){
                int t = 0x3f3f3f3f;
                if (i == 1 || arr1[i - 1] > arr1[i - 2])
                    t = min(t, g[i - 1]);
                if (lb[i] >= 1 && lb[i] <= m)
                    t = min(t, mini[lb[i]]);
                g[i] = min(g[i], t);
                
                t = 0x3f3f3f3f;
                if (i == 1 || arr2[j - 1] > arr1[i - 2])
                    t = min(t, g[i - 1]);
                t = min(t, mmini);
                f[i][j] = t + 1;
                mmini = min(mmini, f[i - 1][j]);
            }
            mini[0] = 0x3f3f3f3f;
            for (int j = 1; j <= m; ++j)
                mini[j] = min(mini[j - 1], f[i][j]);
        }
        int ans = g[n];
        for (int i = 1; i <= m; ++i)
            ans = min(ans, f[n][i]);
        return ans == 0x3f3f3f3f ? -1: ans;
    }
};
Solution sol;
void init(){
    vector<int> vec1{23,10,9,12,3,14,21,16,7,10,17,12}, vec2{6,5,0,15,2,17,4,11,6,5,8,15,10,1,20,11,14,13,8};
    cout << sol.makeArrayIncreasing(vec1, vec2);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
