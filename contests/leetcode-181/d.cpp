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
    int f[100005];
public:
    string longestPrefix(string s) {
        f[0] = -1;
        int l = s.length();
        for (int j = -1, i = 1; i < l; ++i){
            while (j > -1 && s[j + 1] != s[i])
                j = f[j];
            if (s[j + 1] == s[i])
                f[i] = ++j;
            else f[i] = -1;
        }
        return s.substr(0, f[l - 1] + 1);
    }
};
Solution sol;
void init(){
    string s("babbb");
    cout << sol.longestPrefix(s)    ;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
