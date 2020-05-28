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
    string dfs(int l, int& r, string& s){
        string res;
        for (int i = l; ; ++i){
            if (s[i] == ']'){
                r = i;
                break;
            }
            if (isdigit(s[i])){
                int x = 0, j = i;
                while (s[j] != '[')
                    x = x * 10 + s[j] - '0', 
                    ++j;
                ++j;
                int nxt;
                string res1 = dfs(j, nxt, s);
                while (x--) res += res1;
                i = nxt;
            }else res.push_back(s[i]);
        }
        return res;
    }
public:
    string decodeString(string s) {
        s.push_back(']');
        int dummy;
        return dfs(0, dummy, s);
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
