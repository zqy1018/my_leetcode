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

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec){
    for (auto x: vec)
        os << x << " ";
    os << endl;
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<vector<T>>& vec){
    for (auto& v: vec){
        for (auto x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}

class Solution {
    int f[105][22][105];
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(f, 0x3f, sizeof(f));
        if (houses[0] == 0){
            for (int j = 0; j < n; ++j)
                f[0][j][1] = cost[0][j];
        }else {
            f[0][houses[0] - 1][1] = 0;
        }
        for (int i = 1; i < m; ++i){
            if (houses[i] == 0){
                for (int j = 0; j < n; ++j){
                for (int lst = 0; lst < n; ++lst){
                    if (lst == j){
                        for (int t = 1; t <= target; ++t)
                            f[i][j][t] = min(f[i][j][t], f[i - 1][lst][t]);
                    }else {
                        for (int t = 1; t <= target; ++t)
                            f[i][j][t] = min(f[i][j][t], f[i - 1][lst][t - 1]);
                    }
                }
            }
            }else {
                int j = houses[i] - 1;
                for (int lst = 0; lst < n; ++lst){
                    if (lst == j){
                        for (int t = 1; t <= target; ++t)
                            f[i][j][t] = min(f[i][j][t], f[i - 1][lst][t]);
                    }else {
                        for (int t = 1; t <= target; ++t)
                            f[i][j][t] = min(f[i][j][t], f[i - 1][lst][t - 1]);
                    }
                }
            }
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i)
            ans = min(ans, f[m - 1][i][target]);
        return ans == 0x3f3f3f3f ? -1: ans;
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