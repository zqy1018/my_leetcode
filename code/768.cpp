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

int f[2005];
class Solution {
public:
    unordered_map<int, int> mp;
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0, n = arr.size();
        for (int i = 0; i < n; ++i) f[i] = arr[i];
        sort(f, f + n);
        for (int i = 0; i < n; ){
            int j = i;
            while (j < n && f[i] == f[j])
                ++j;
            mp[f[i]] = i, i = j;
        }
        int rtm = -1;
        for (int i = 0; i < n; ++i){
            rtm = max(rtm, mp[arr[i]]), ++mp[arr[i]];
            if (rtm == i) ++ans;
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
