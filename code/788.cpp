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
    bool judge(int x){
        bool flag = false;
        while (x > 0){
            if (x % 10 == 3 || x % 10 == 4 || x % 10 == 7)  
                return false;
            if (x % 10 == 2 || x % 10 == 5 || x % 10 == 6 || x % 10 == 9)
                flag = true;
            x /= 10;
        }
        return flag;
    }
    int rotatedDigits(int N) {
        int cnt = 0;
        for (int i = 1; i <= N; ++i)
            cnt += judge(i);
        return cnt;
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
