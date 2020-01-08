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
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size(), ans = n + 1;
        for (int i = 1; i <= 6; ++i){
            bool flag = true;
            int cnt = 0;
            for (int j = 0; j < n; ++j){
                if (A[j] == i) continue;
                else {
                    if (B[j] != i){
                        flag = false;
                        break;
                    }else ++cnt;
                }
            }
            if (flag) ans = min(ans, cnt);
            flag = true, cnt = 0;
            for (int j = 0; j < n; ++j){
                if (B[j] == i) continue;
                else {
                    if (A[j] != i){
                        flag = false;
                        break;
                    }else ++cnt;
                }
            }
            if (flag) ans = min(ans, cnt);
        }
        return (ans > n ? -1: ans);
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
