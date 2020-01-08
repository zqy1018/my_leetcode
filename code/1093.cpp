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
    vector<double> sampleStats(vector<int>& count) {
        int mini = -1, maxi = 0, maxp = 0, maxpp;
        long long cnt = 0, tot = 0;
        for (int i = 0; i < 256; ++i){
            if (!count[i]) continue;
            cnt += count[i];
            tot += 1ll * i * count[i];
            if (mini < 0) mini = i;
            maxi = i;
            if (count[i] > maxp) maxp = count[i], maxpp = i;
        }
        long long cnt2 = 0;
        int mid1 = 0, mid2 = 0;
        for (int i = 0; i < 256; ++i){
            if (!count[i]) continue;
            cnt2 += count[i];
            if (cnt2 - count[i] < ((cnt + 1) >> 1) && 
                cnt2 >= ((cnt + 1) >> 1))
                mid1 = i;
            if (cnt2 - count[i] < ((cnt + 2) >> 1) && 
                cnt2 >= ((cnt + 2) >> 1))
                mid2 = i;
        }
        vector<double> ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        ans.push_back(1.0 * tot / cnt);
        ans.push_back(0.5 * (mid1 + mid2));
        ans.push_back(maxpp);
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
