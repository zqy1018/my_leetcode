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
    int ordinalOfDate(string date) {
        int y = 0, m = 0, d = 0;
        for (int i = 0; i < 4; ++i) 
            y = y * 10 + date[i] - '0';
        for (int i = 5; i < 7; ++i) 
            m = m * 10 + date[i] - '0';
        for (int i = 8; i < 10; ++i)
            d = d * 10 + date[i] - '0';
        int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
            ++month[1];
        int ans = 0;
        for (int i = 0; i < m - 1; ++i)
            ans += month[i];
        ans += d;
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
