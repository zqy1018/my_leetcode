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

int sum[100005][4];
int get(char c){
    if (c == 'Q') return 0;
    if (c == 'W') return 1;
    if (c == 'E') return 2;
    if (c == 'R') return 3;
}
class Solution {
public:
    int balancedString(string s) {
        int le = s.length();
        int t = (le >> 2);
        int l = 0, r = le;
        sum[0][0] = sum[0][1] = sum[0][2] = sum[0][3] = 0;
        for (int i = 0; i < le; ++i){
            for (int j = 0; j < 4; ++j)
                sum[i + 1][j] = sum[i][j];
            ++sum[i + 1][get(s[i])];
        }
        int cnt[5];
        while (r > l)   {
            int mid = (l + r) >> 1;
            bool flag = false;
            for (int i = 0; i + mid <= le; ++i){
                for (int j = 0; j < 4; ++j)
                    cnt[j] = sum[le][j] - sum[i + mid][j] + sum[i][j];
                if (cnt[0] <= t && cnt[1] <= t && cnt[2] <= t && cnt[3] <= t){
                    flag = true;
                    break;
                }
            }
            if (flag) r = mid;
            else l = mid + 1;
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
