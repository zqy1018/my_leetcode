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

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0, n = arr.size();
        vector<int> arr2 = arr;
        sort(arr2.begin(), arr2.end());
        int curmin = INT_MAX, curmax = INT_MIN;
        for (int i = 0, lst = 0; i < n; ++i){
            curmin = min(curmin, arr[i]);
            curmax = max(curmax, arr[i]);
            if (curmin == arr2[lst] && curmax == arr2[i])
                ++ans, lst = i + 1, curmin = INT_MAX, curmax = INT_MIN;
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
