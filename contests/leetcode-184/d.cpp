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
    int f[5005][28];
    bool ok[28];
public:
    int numOfWays(int n) {
        const int M = 1000000007;
        for (int i = 0; i < 27; ++i){
            int c1 = i / 9, c2 = (i % 9) / 3, c3 = i - c1 * 9 - c2 * 3;
            if (c1 != c2 && c2 != c3) ok[i] = true, f[1][i] = 1;
        }
        for (int i = 2; i <= n; ++i){
            for (int j = 0; j < 27; ++j){
                if (!ok[j]) continue;
                for (int k = 0; k < 27; ++k){
                    if (!ok[k]) continue;
                    int c1 = j / 9, c2 = (j % 9) / 3, c3 = j - c1 * 9 - c2 * 3;
                    int d1 = k / 9, d2 = (k % 9) / 3, d3 = k - d1 * 9 - d2 * 3;
                    if (c1 == d1 || c2 == d2 || c3 == d3) continue;
                    f[i][j] = (f[i][j] + f[i - 1][k]) % M;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 27; ++i)
            ans = (ans + f[n][i]) % M;
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
