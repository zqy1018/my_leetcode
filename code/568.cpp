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
    int f[105][105];
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size(), k = days[0].size();
        memset(f, -1, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= k; ++i){
            for (int j = 0; j < n; ++j){
                for (int fr = 0; fr < n; ++fr){
                    if (f[i - 1][fr] < 0) continue;
                    if (fr == j || flights[fr][j])
                        f[i][j] = max(f[i][j], f[i - 1][fr] + days[j][i - 1]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, f[k][i]);
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
