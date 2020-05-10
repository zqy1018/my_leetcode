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

const int M = 1000000007;
class Solution {
    int f[55][55][15];
    int sum[55][55];
public:
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size(), m = pizza[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                sum[i + 1][j + 1] = sum[i + 1][j] + (pizza[i][j] == 'A' ? 1: 0);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                sum[i + 1][j + 1] += sum[i][j + 1];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (sum[n][m] - sum[i - 1][m] - sum[n][j - 1] + sum[i - 1][j - 1] > 0)
                    f[i][j][1] = 1;
        for (int t = 2; t <= k; ++t){
            for (int i = n; i >= 1; --i)
                for (int j = m; j >= 1; --j){
                    for (int u = i - 1; u >= 1; --u)
                        if (sum[i - 1][m] - sum[u - 1][m] - sum[i - 1][j - 1] + sum[u - 1][j - 1] > 0)
                            f[u][j][t] = (f[u][j][t] + f[i][j][t - 1]) % M;
                    for (int u = j - 1; u >= 1; --u)
                        if (sum[n][j - 1] - sum[n][u - 1] - sum[i - 1][j - 1] + sum[i - 1][u - 1] > 0)
                            f[i][u][t] = (f[i][u][t] + f[i][j][t - 1]) % M;
                }
        }
        return f[1][1][k];
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
