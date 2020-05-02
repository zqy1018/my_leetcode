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
    vector<char> t1, t2;
public:
    bool checkIfCanBreak(string s1, string s2) {
        for (char c: s1) t1.push_back(c);
        for (char c: s2) t2.push_back(c);
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        bool flag = true;
        int n = t1.size();
        for (int i = 0; i < n; ++i)
            if (t1[i] < t2[i]){
                flag = false;
                break;
            }
        if (flag) return true;
        flag = true;
        for (int i = 0; i < n; ++i)
            if (t2[i] < t1[i]){
                flag = false;
                break;
            }
        if (flag) return true;
        return false;
    }
};
Solution sol;
void init(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << sol.checkIfCanBreak(s1, s2);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
