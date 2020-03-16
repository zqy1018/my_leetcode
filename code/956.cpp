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
    int f[10005], g[10005];
public:
    int tallestBillboard(vector<int>& rods) {
        memset(f, -1, sizeof(f));
        int sum = 0;
        for (int x: rods) sum += x;
        f[0 + sum] = 0;
        for (int x: rods){
            memset(g, -1, sizeof(g));
            for (int i = -sum + x; i <= sum; ++i)
                if (f[i + sum] >= 0)
                    g[i - x + sum] = max(f[i + sum], g[i - x + sum]);
            for (int i = -sum; i <= sum - x; ++i)
                if (f[i + sum] >= 0)
                    g[i + x + sum] = max(f[i + sum] + x, g[i + x + sum]);
            memcpy(f, g, sizeof(int) * (sum + sum + 1));
        }
        return f[0 + sum];
    }
};
Solution sol;
void init(){
    vector<int> vec{1, 2, 3};
    cout << sol.tallestBillboard(vec) << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
