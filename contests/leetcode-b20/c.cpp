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
    int nxta[50005], nxtb[50005], nxtc[50005];
public:
    int numberOfSubstrings(string s) {
        int l = s.length();
        nxta[l] = nxtb[l] = nxtc[l] = -1;
        for (int i = l - 1; i >= 0; --i){
            nxta[i] = (s[i] == 'a' ? i: nxta[i + 1]);
            nxtb[i] = (s[i] == 'b' ? i: nxtb[i + 1]);
            nxtc[i] = (s[i] == 'c' ? i: nxtc[i + 1]);
        }
        int ans = 0;
        for (int i = 0; i < l; ++i){
            int na = nxta[i], nb = nxtb[i], nc = nxtc[i];
            if (na < 0 || nb < 0 || nc < 0) break;
            int t = max(na, max(nb, nc));
            ans += l - t;
        }
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
