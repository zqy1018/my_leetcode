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

ostream& operator << (ostream& os, const vector<int>& vec){
    for (int x: vec)
        os << x << " ";
    os << endl;
    return os;
}

ostream& operator << (ostream& os, const vector<vector<int>>& vec){
    for (auto& v: vec){
        for (int x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}

class Solution {
    int pro[130];
    stack<long long> opr;
    stack<char> opt;
    void calc(){
        long long u = opr.top(); opr.pop();
        long long v = opr.top(); opr.pop();
        char c = opt.top(); opt.pop();
        if (c == '+') opr.push(v + u);
        if (c == '-') opr.push(v - u);
        if (c == '*') opr.push(v * u);
        if (c == '/') opr.push(v / u);
    }
public:
    int calculate(string s) {
        if (!s.length()) return 0;
        pro['+'] = pro['-'] = 1, 
        pro['*'] = pro['/'] = 2;
        pro['('] = 0;
        opt.push('(');
        s.push_back(')');
        long long x = -1, f = 1;
        char lst = '(';
        for (char c: s){
            if (isdigit(c)){
                if (x < 0) x = 0;
                x = x * 10 + c - '0';
            }else {
                if (c == '('){
                    opt.push('(');
                }else if (c == ')'){
                    if (x >= 0)
                        opr.push(f * x), x = -1, f = 1;
                    while (opt.top() != '(')
                        calc();
                    opt.pop();
                }else if (c != ' '){
                    if (x < 0 && lst != ')'){
                        if (c == '-') f = -f;
                    }else {
                        if (x >= 0)
                            opr.push(f * x), x = -1, f = 1;
                        while (pro[opt.top()] >= pro[c])
                            calc();
                        opt.push(c);
                    }
                }else continue;
            }
            lst = c;
        }
        return opr.top();
    }
};
Solution sol;
void init(){
    string a("------------1*---------------1");
    cout << sol.calculate(a) << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
