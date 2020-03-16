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

class Sea {
  public:
    bool hasShips(vector<int> topRight, vector<int> bottomLeft);
};


class Solution {
public:
    int dfs(Sea& sea, int btx, int bty, int tpx, int tpy){
        if (btx > tpx || bty > tpy) return 0;
        int res = 0;
        vector<int> vec1{btx, bty}, vec2{tpx, tpy};
        bool tt = sea.hasShips(vec2, vec1);
        if (!tt) return 0;
        if (tt && btx == tpx && bty == tpy) return 1;
        int midx = (btx + tpx) >> 1, midy = (bty + tpy) >> 1;
        res += dfs(sea, btx, midy + 1, midx, tpy);
        res += dfs(sea, btx, bty, midx, midy);
        res += dfs(sea, midx + 1, midy + 1, tpx, tpy);
        res += dfs(sea, midx + 1, bty, tpx, midy + 1);
        return res;
    }
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        return dfs(sea, bottomLeft[0], bottomLeft[1], topRight[0], topRight[1]);
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
