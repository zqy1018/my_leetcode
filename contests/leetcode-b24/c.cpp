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
    vector<string> s;
    string tmp;
    void dfs(int cur, int lim){
        if (cur == lim){
            s.push_back(tmp);
            return ;
        }
        for (int i = 0; i < 3; ++i){
            if (tmp[cur - 1] == i + 'a')
                continue;
            tmp[cur] = i + 'a';
            dfs(cur + 1, lim);
        }
    }
public:
    string getHappyString(int n, int k) {
        for (int i = 0; i < n; ++i)
            tmp.push_back('a');
        dfs(1, n);
        tmp[0] = 'b', dfs(1, n);
        tmp[0] = 'c', dfs(1, n);
        sort(s.begin(), s.end());
        if (k > s.size()) return string("");
        return s[k - 1];
    }
};
Solution sol;
void init(){
    cout << sol.getHappyString(10, 100);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
