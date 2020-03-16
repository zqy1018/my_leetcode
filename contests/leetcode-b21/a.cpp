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
    string sortString(string s) {
        for (char c: s) 
            ++cnt[c - 'a'];
        string ans;
        int left = s.length();
        for (; left > 0; ){
            for (int i = 0; i < 26; ++i)
                if (cnt[i]) --cnt[i], --left, ans.push_back(i + 'a');
            for (int i = 25; i >= 0; --i)
                if (cnt[i]) --cnt[i], --left, ans.push_back(i + 'a');
        }
        return ans;
    }
};
Solution sol;
void init(){
    string s("rat");
    cout << sol.sortString(s);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
