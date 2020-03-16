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

string ans[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int weekd(int y, int m, int d){
    if (m <= 2) m += 12, --y;
    int yc = y / 100, yy = y % 100;
    int t = 7 + (yy + (yy >> 2) + (yc >> 2) - (yc << 1) + (26 * (m + 1) / 10) + d - 1) % 7;
    return (t > 7 ? t - 7: t);
}
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        return ans[weekd(year, month, day) - 1];
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
