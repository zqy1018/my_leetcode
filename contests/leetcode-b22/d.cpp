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
    int f[1005][1005];
    int maxx(int a, int b, int c){
        return max(a, max(b, c));
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        for (int i = 0; i < n; ++i)
            slices.push_back(slices[i]);
        for (int i = 0; i + 2 < n + n; ++i){
            f[i][i + 2] = maxx(slices[i], slices[i + 1], slices[i + 2]);
        }
        for (int l = 6; l <= n; l += 3){
            for (int i = 0; i + l - 3 - 1 < n + n; ++i){
                if (i - 3 >= 0)
                    f[i - 3][i + l - 3 - 1] = max(f[i - 3][i + l - 3 - 1], f[i][i + l - 3 - 1] + maxx(slices[i - 3], slices[i - 2], slices[i - 1]));
                if (i - 2 >= 0 && i + l - 2 - 1 < n + n)
                    f[i - 2][i + l - 2 - 1] = max(f[i - 2][i + l - 2 - 1], f[i][i + l - 3 - 1] + maxx(slices[i - 2], slices[i - 1], slices[i + l - 2 - 1]));
                if (i - 1 >= 0 && i + l - 1 - 1 < n + n)
                    f[i - 1][i + l - 1 - 1] = max(f[i - 1][i + l - 1 - 1], f[i][i + l - 3 - 1] + maxx(slices[i - 1], slices[i + l - 2 - 1], slices[i + l - 1 - 1]));
                if (i + l - 1 - 1 < n + n)
                    f[i - 1][i + l - 1 - 1] = max(f[i - 1][i + l - 1 - 1], f[i][i + l - 3 - 1] + maxx(slices[i - 1], slices[i + l - 2 - 1], slices[i + l - 1 - 1]));
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, f[i][i + n - 1]);
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
