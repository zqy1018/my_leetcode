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
    bool check(string& command, int cntx, int cnty, int targx, int targy){
        int stx = targx / cntx, sty = targy / cnty;
        int st = min(stx, sty);
        int curx = st * cntx, cury = st * cnty;
        if (curx == targx && cury == targy) return true;
        for (char c: command){
            if (c == 'U') ++cury;
            else ++curx;
            if (curx == targx && cury == targy) return true;
        }
        return false;
    }
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        int cntx = 0, cnty = 0;
        for (char c: command)
            if (c == 'U') ++cnty;
            else ++cntx;
        for (vector<int>& p: obstacles){
            if (p[0] > x || p[1] > y) continue;
            if (check(command, cntx, cnty, p[0], p[1]))
                return false;
        }
        if (check(command, cntx, cnty, x, y))
            return true;
        return false;
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
