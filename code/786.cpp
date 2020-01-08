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
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double l = 0.0, r = 1.0;
        int n = A.size();
        for (; ; ){
            double mid = (l + r) * 0.5;
            int cnt = 0, p = 0, q = 1;
            for (int i = 1, j = 0; i < n; ++i){
                while (j < n && A[j] <= A[i] * mid)
                    ++j;
                cnt += j;
                if (j > 0 && p * A[i] < q * A[j - 1])
                    p = A[j - 1], q = A[i];
            }
            if (cnt == K) return vector<int>{p, q};
            if (cnt < K) l = mid;
            else r = mid;
        }
        return vector<int>();
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
