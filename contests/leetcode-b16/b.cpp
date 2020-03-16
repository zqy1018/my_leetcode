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
    int findBestValue(vector<int>& arr, int target) {
        int l = 0, r = 100000;
        while (r > l){
            int mid = (l + r + 1) >> 1;
            int sm = 0;
            for (int x: arr)    
                sm += min(x, mid);
            if (sm <= target) l = mid;
            else r = mid - 1;
        }
        int sm1 = 0, sm2 = 0;
        for (int x: arr)    
            sm1 += min(l, x), 
            sm2 += min(l + 1, x);
        if (abs(sm1 - target) <= abs(sm2 - target))
            return l;
        return l + 1;
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
