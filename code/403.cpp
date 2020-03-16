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
    bool f[1105][1105];
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (stones[1] != 1)
            return false;
        f[1][1] = true;
        for (int i = 2; i < n; ++i){
            for (int j = i - 1; j >= 1; --j){
                int d = stones[i] - stones[j];
                if (d > i) break;
                if (d > 0) f[i][d] = f[i][d] || f[j][d - 1];
                f[i][d] = f[i][d] || f[j][d] || f[j][d + 1];
            }
        }
        for (int i = 0; i < n; ++i)
            if (f[n - 1][i]) return true;
        return false;
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
