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

int id[100];
bool unable[100];
class Solution {
public:
    int maxLength(vector<string>& arr) {
        memset(id, 0, sizeof(id));
        memset(unable, 0, sizeof(unable));
        int n = arr.size();
        for (int  i = 0; i < n; ++i){
            int l = arr[i].length();
            for (int j = 0; j < l; ++j){
                if ((id[i] & (1 << (arr[i][j] - 'a'))) == 0)
                    id[i] |= (1 << (arr[i][j] - 'a'));
                else {
                    unable[i] = true;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < (1 << n); ++i){
            int tt = 0, res = 0;
            bool flag = true;
            for (int j = 1, k = 0; k < n; j <<= 1, ++k){
                if (j & i){
                    if (unable[k]) {
                        flag = false;
                        break;
                    }else {
                        if ((tt & id[k]) != 0){
                            flag = false;
                            break;
                        }else {
                            tt |= id[k], res += arr[k].length();
                        }
                    }
                }
            }
            if (flag)
                ans = max(ans, res);
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
