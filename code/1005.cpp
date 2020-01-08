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
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int cnt = 0, mini = -1;
        for (int i: A){
            if (i >= 0){
                mini = i;
                break;
            }else ++cnt;
        }
        int ans = 0;
        if (K <= cnt){
            for (int i = 0; i < K; ++i)
                A[i] = -A[i], ans += A[i];
            for (int i = K; i < A.size(); ++i)
                ans += A[i];
        }else {
            for (int i = 0; i < cnt; ++i)
                A[i] = -A[i], ans += A[i];
            K -= cnt;
            if (K & 1) {
                if (cnt && mini > A[cnt - 1])
                    ans -= 2 * A[cnt - 1], ans += mini;
                else ans -= mini;
            }else ans += mini;
            for (int i = cnt + 1; i < A.size(); ++i)
                ans += A[i];
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
