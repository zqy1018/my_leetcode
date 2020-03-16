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

bool vis[10005];
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        memset(vis, 0, sizeof(vis));
        int n = intervals.size();
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (i == j) continue;
                if (vis[j]) continue;
                if (intervals[i][0] >= intervals[j][0] && intervals[j][1] >= intervals[i][1]){
                    vis[i] = true;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)     
            if (!vis[i]) ++ans;
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
