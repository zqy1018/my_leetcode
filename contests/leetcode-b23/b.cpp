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
    int cnt[30];
public:
    bool canConstruct(string s, int k) {
        for (char c: s)
            ++cnt[c - 'a'];
        if (s.length() < k) return false;
        int res = 0;
        for (int i = 0; i < 26; ++i){
            if (cnt[i] & 1) ++res;
        }
        if (res > k) return false;
        return true;
    }
};
Solution sol;
void init(){
    cout << sol.canConstruct("leetcode", 3);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
