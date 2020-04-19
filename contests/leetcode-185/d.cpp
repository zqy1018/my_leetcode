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
    int f[55][105][55];
public:
    int numOfArrays(int n, int m, int k) {
        const int M = 1000000007;
        memset(f, 0, sizeof(f) ) ;
        for (int i = 1; i <= m; ++i){
            f[1][i][1] = 1;
        }
        for (int i = 2; i <= n; ++i){
            for (int kk = 1; kk <= k; ++kk){
                int sm = 0;
                for (int j = 1; j <= m; ++j){
                    f[i][j][kk] = 1ll * j * f[i - 1][j][kk] % M;
                    f[i][j][kk] = (f[i][j][kk] + sm) % M;
                    sm = (sm + f[i - 1][j][kk - 1]) % M;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; ++i)
            ans = (ans + f[n][i][k]) % M;
        return ans;
    }
};
Solution sol;
void init(){
    cout << sol.numOfArrays(5, 2, 3);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
