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
    unordered_map<int, int> mp[2005];
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size(), ans = 2;
        mp[1][A[1] - A[0]] = 2;
        for (int i = 2; i < n; ++i){
            mp[i][A[i] - A[0]] = 2;
            for (int j = i - 1; j >= 1; --j){
                int d = A[i] - A[j];
                if (!mp[j].count(d)) {
                    if (!mp[i].count(d)) mp[i][d] = 2;
                }else {
                    if (!mp[i].count(d)) mp[i][d] = 0;
                    mp[i][d] = max(mp[i][d], mp[j][d] + 1) , 
                    ans = max(ans, mp[i][d]);
                }
            }
        }
        cout << mp[14][0] << endl;
        return ans;
    }
};
/*[12,28,13,6,34,
    36,53,24,29,2,
    23,0,22,25,53,
    34,23,50,35,43,
    53,11,48,56,44,
    53,31,6,31,57,
    46,6,17,42,48,
    28,5,24,0,14,
    43,12,21,6,30,
    37,16,56,19,45,
    51,10,22,38,39,
    23,8,29,60,18]*/
Solution sol;
void init(){
    vector<int> vec{12,28,13,6,34,36,53,24,29,2,23,0,22,25,53,34,23,50,35,43,53,11,48,56,44,53,31,6,31,57,46,6,17,42,48,28,5,24,0,14,43,12,21,6,30,37,16,56,19,45,51,10,22,38,39,23,8,29,60,18};
    cout << sol.longestArithSeqLength(vec);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
