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
    unordered_map<int, int> mp, nxt;
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if (n % W) return false;
        sort(hand.begin(), hand.end());
        for (int i = 0; i < n; ){
            int j = i;
            while (j < n && hand[i] == hand[j])
                ++j;
            mp[hand[i]] = j - i;
            if (j < n) nxt[i] = j;
            i = j;
        }
        int cur = 0, curp = 0;
        while (cur * W < n){
            int nm = hand[curp];
            cur += mp[nm];
            for (int i = hand[curp], j = 0; j < W; ++j, ++i){
                if (!mp.count(i) || mp[i] < mp[nm])
                    return false;
                mp[i] -= mp[nm];
            }
            while (nxt.count(curp) && mp[hand[curp]] == 0)
                curp = nxt[curp];
        }
        return true;
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
