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

int lis1[105][105], cnt1[105], tot1;
int lis2[105][105], cnt2[105], tot2;
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        tot1 = cnt1[0] = 0;
        for (char c: pattern){
            if (isupper(c)) 
                lis1[++tot1][0] = c, cnt1[tot1] = 0;
            else 
                lis1[tot1][++cnt1[tot1]] = c;
        }
        for (string& s: queries){
            tot2 = cnt2[0] = 0;
            for (char c: s){
                if (isupper(c)) 
                    lis2[++tot2][0] = c, cnt2[tot2] = 0;
                else 
                    lis2[tot2][++cnt2[tot2]] = c;
            }
            if (tot1 != tot2) ans.push_back(false);
            else {
                int cur = 1;
                for (int i = 1; i <= cnt2[0]; ++i)
                    if (cur <= cnt1[0] && lis1[0][cur] == lis2[0][i])
                        ++cur;
                if (cur < cnt1[0]) {
                    ans.push_back(false);
                    continue;
                }

                bool flag = true;
                for (int i = 1; i <= tot1; ++i){
                    if (lis1[i][0] != lis2[i][0]) {
                        flag = false;
                        break;
                    }
                    cur = 1;
                    for (int j = 1; j <= cnt2[i]; ++j)
                        if (cur <= cnt1[i] && lis1[i][cur] == lis2[i][j])
                            ++cur;
                    if (cur < cnt1[i])  {
                        flag = false;
                        break;
                    }
                }
                
                ans.push_back(flag);
            }
        }
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
