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

ostream& operator << (ostream& os, const vector<int>& vec){
    for (int x: vec)
        os << x << " ";
    os << endl;
    return os;
}

ostream& operator << (ostream& os, const vector<vector<int>>& vec){
    for (auto& v: vec){
        for (int x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}

class Solution {
    int f[105][105];
public:
    int numMusicPlaylists(int N, int L, int K) {
        if (L < N) return 0;
        const int M = 1000000007;
        f[0][0] = 1;
        for (int i = 1; i <= L; ++i)
            for (int j = 1; j <= N; ++j)
                f[i][j] = 1ll * f[i - 1][j - 1] * (N - j + 1) % M + 
                    1ll * f[i - 1][j] * max(j - K, 0) % M,
                f[i][j] %= M;
        return f[L][N];
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
