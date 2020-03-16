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
    int n, m;
    bool cmp(int st1, int st2, string& s, string& t){
        if (n - st1 != m - st2)
            return false;
        for (int i = 0; i < n - st1; ++i)
            if (s[st1 + i] != t[st2 + i])
                return false;
        return true;
    } 
    bool isOneEditDistance(string s, string t) {
        if (abs(s.length() - t.length()) > 1) return false;
        int cur = 0;
        n = s.length(), m = t.length();
        while (cur < n && cur < m && s[cur] == t[cur])
            ++cur;
        if (cur == n || cur == m)
            return n != m;
        return cmp(cur + 1, cur, s, t) || cmp(cur, cur + 1, s, t) || cmp(cur + 1, cur + 1, s, t);
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
