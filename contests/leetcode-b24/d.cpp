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
    int cnt[105], f[100005];
    int ten[15];
public:
    int numberOfArrays(string s, int k) {
        const int M = 1000000007;
        f[0] = 1;
        ten[0] = 1;
        for (int i = 1; i < 10; ++i)
            ten[i] = ten[i - 1] * 10;
        int n = s.length();
        for (int i = 1; i <= n; ++i){
            long long x = 0;
            for (int j = i; j >= 1; --j){
                if (s[j - 1] == '0' && x > 0)
                    continue;
                x += 1ll * (s[j - 1] - '0') * ten[i - j];
                if (x > k) break;
                if (x > 0) f[i] = (f[i] + f[j - 1]) % M;
            }
        }
        return f[n];
    }
};
Solution sol;
void init(){
    cout << sol.numberOfArrays("604516296181603152696", 696);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
