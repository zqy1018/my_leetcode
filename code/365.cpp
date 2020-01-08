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
    int xx, yy, zz;
    bool flag;
    set<pair<int, int>> pp;
    void dfs(int x, int y){
        cout << x << "  " << y << endl;
        if (x + y == zz) flag = true;
        if (flag) return ;
        pair<int, int> tmp;
        tmp.first = xx, tmp.second = y;
        if (!pp.count(tmp))
            pp.insert(tmp), dfs(xx, y);
        tmp.first = x, tmp.second = yy;
        if (!pp.count(tmp))
            pp.insert(tmp), dfs(x, yy);

        if (y + x <= yy){
            tmp.first = 0, tmp.second = x + y;
            if (!pp.count(tmp))
                pp.insert(tmp), dfs(0, x + y);
        }else{
            tmp.first = x + y - yy, tmp.second = yy;
            if (!pp.count(tmp))
                pp.insert(tmp), dfs(x + y - yy, yy);
        }

        if (y + x <= xx){
            tmp.first = x + y, tmp.second = 0;
            if (!pp.count(tmp))
                pp.insert(tmp), dfs(x + y, 0);
        }else{
            tmp.first = xx, tmp.second = x + y - xx;
            if (!pp.count(tmp))
                pp.insert(tmp), dfs(xx, x + y - xx);
        }
        
        tmp.first = 0, tmp.second = y;
        if (!pp.count(tmp))
            pp.insert(tmp), dfs(0, y);
        tmp.first = x, tmp.second = 0;
        if (!pp.count(tmp))
                pp.insert(tmp), dfs(x, 0);
    }
    bool canMeasureWater(int x, int y, int z) {
        if (!z) return true;
        flag = false;
        pp.insert(make_pair(0, 0)), dfs(0, 0);
        return flag;
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
