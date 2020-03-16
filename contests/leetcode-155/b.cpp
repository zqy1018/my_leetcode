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
    long long gcd(long long a, long long b) {
        return (!b) ? a: gcd(b, a % b);
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        long long lcm = 1ll * a * b / gcd(a, b);
        lcm = 1ll * lcm * c / gcd(lcm, c);
        long long lcm1 = 1ll * a * b / gcd(a, b), lcm2 = 1ll * c * b / gcd(c, b), lcm3 = 1ll * a * c / gcd(a, c);
        int l = 1, r = 2000000000;
        while (r > l){
            long long mid = (1ll * l + r) >> 1;
            
            long long cnt = mid / a + mid / b + mid / c - mid / lcm1 - mid / lcm2 - mid / lcm3 + mid / lcm;
            if (cnt < n) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
Solution sol;
void init(){
    cout << sol.nthUglyNumber(1000000000, 2, 217983653, 336916467);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
