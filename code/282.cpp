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

class Solution {
public:
    string tmp, nm;
    vector<string> ans;
    int l, tg;
    stack<long long> opr;
    stack<char> opt;
    void step(){
        while (!opt.empty()){
            long long u = opr.top();
            opr.pop();
            long long v = opr.top();
            opr.pop();
            if (opt.top() == '*') opr.push(u * v);
            else if (opt.top() == '+') opr.push(u + v);
            else opr.push(u - v);
            opt.pop();
        }
    }
    long long calc(){
        long long x = 0;
        for (char c: tmp){
            if (isdigit(c)){
                x = x * 10 + c - '0';
            }else if (c == '*'){
                opr.push(x), x = 0;
                if (!opt.empty() && opt.top() == '*'){
                    long long u = opr.top();
                    opr.pop();
                    long long v = opr.top();
                    opr.pop();
                    opr.push(u * v);
                }else opt.push('*');
            }else {
                opr.push(x), x = 0;
                step();
                opt.push(c);
            }
        }
        step();
        long long res = opr.top();
        opr.pop();
        return res;
    }
    void dfs(int cur, bool lst){            // lst: 上一次是否是运算符
        tmp.push_back(nm[cur]);
        if (cur == l - 1){
            if (calc() == tg) ans.push_back(tmp);
            return ;
        }
        if (nm[cur] != '0' || !lst){            // 不添加运算符
            dfs(cur + 1, false), tmp.pop_back();
        }
        tmp.push_back('+'), dfs(cur + 1, true), tmp.pop_back();
        tmp.push_back('-'), dfs(cur + 1, true), tmp.pop_back();
        tmp.push_back('*'), dfs(cur + 1, true), tmp.pop_back();
        tmp.pop_back();
    }
    vector<string> addOperators(string num, int target) {
        l = num.size(), nm = num;
        dfs(0, true);
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
