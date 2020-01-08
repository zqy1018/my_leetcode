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
    int shipWithinDays(vector<int>& weights, int D) {
        int l = 1, r = 0;
        int n = weights.size();
        for (int t: weights) r += t;
        while (r > l){
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int i = 0; i < n; ){
                int j = i, sm = 0;
                while (j < n && sm + weights[j] <= mid)   
                    sm += weights[j], ++j;
                if (i == j){
                    cnt = D + 1;
                    break;
                }
                ++cnt, i = j;
            }
            if (cnt <= D) r = mid;
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
