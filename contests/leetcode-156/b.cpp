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
    int equalSubstring(string s, string t, int maxCost) {
        int l = 0, r = s.length();
        while (r > l){
            int mid = (l + r + 1) >> 1;
            int cur = 0;
            for (int i = 0; i < mid; ++i)
                cur += abs(s[i] - t[i]);
            bool flag = false;
            for (int i = mid; i < s.length(); ++i){
                if (cur <= maxCost) {
                    flag = true;
                    break;
                }
                cur -= abs(s[i - mid] - t[i - mid]);
                cur += abs(s[i] - t[i]);
            }
            if (cur <= maxCost) flag = true;
            if (flag) l = mid;
            else r = mid - 1;
        }
        return l;
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
