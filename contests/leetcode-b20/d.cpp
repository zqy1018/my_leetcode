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
    int f[505][505];
public:
    int countOrders(int n) {
        const int M = 1000000007;
        f[0][0] = 1;
        for (int i = 1; i <= n + n; ++i){
            for (int j = 1; j <= n; ++j){
                int k = i - j;
                if (k < 0 || k > n) continue; 
                int tt = 1ll * f[j - 1][k] * (n - j + 1) % M;
                if (j > k - 1 && k > 0){
                    int t2 = 1ll * f[j][k - 1] * (j - k + 1) % M;
                    tt = (tt + t2) % M;
                }
                f[j][k] = tt;
            }
        }
        return f[n][n];
    }
};
Solution sol;
void init(){
    cout << sol.countOrders(1);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
