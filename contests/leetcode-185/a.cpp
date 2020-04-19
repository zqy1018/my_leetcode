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
    string a, b;
public:
    string reformat(string s) {
        for (char c: s){
            if (isdigit(c)) a.push_back(c);
            else b.push_back(c);
        }
        int la = a.length(), lb = b.length();
        if (abs(la - lb) > 1) return string("");
        string ans;
        if (la > lb){

            for (int i = 0; i < lb; ++i)
                ans.push_back(a[i]), ans.push_back(b[i]);
            ans.push_back(a[lb]);
        }else if (lb > la){
            for (int i = 0; i < la; ++i)
                ans.push_back(b[i]), ans.push_back(a[i]);
            ans.push_back(b[la]);
        }else {
            for (int i = 0; i < lb; ++i)
                ans.push_back(a[i]), ans.push_back(b[i]);
        }
        return ans;    }
};
Solution sol;
void init(){
    cout << sol.reformat( "ab123");
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
