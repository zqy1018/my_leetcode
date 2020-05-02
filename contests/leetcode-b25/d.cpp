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
    int f[45][2000];
    int ok[45];
    int lowbit(int x){
        return x & (-x) ;
    }
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        for (int i = 0; i < n; ++i) {
            for (int x: hats[i])
                ok[x] |= (1 << i);
        }
        f[0][0] = 1;
        for (int i = 1; i <= 40; ++i){
            for (int p = 0; p < (1 << n); ++p)
                f[i][p] = f[i - 1][p];
            for (int p = 0; p < (1 << n); ++p){
                int tmp = ok[i];
                while (tmp > 0){
                    
                    int lb = lowbit(tmp);
                    tmp -= lb;
                    if (lb & p) continue;
                    f[i][lb | p] = (f[i][lb | p] + f[i - 1][p]) % M;
                }
            }
        }
        return f[40][(1 << n) - 1];
    }
};
Solution sol;
void init(){
    vector<vector<int>> vec{{1,2,3},{2,3,5,6},{1,3,7,9},{1,8,9},{2,5,7}};
    cout << sol.numberWays(vec);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
