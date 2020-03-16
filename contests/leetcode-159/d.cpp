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

int kp[100005], f[100005];
class Solution {
public:
    unordered_map<int, int> mp;
    unordered_map<int, vector<int>> mp2;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        for (int i = 0; i < n; ++i)
            kp[i] = startTime[i];
        for (int i = 0; i < n; ++i)
            kp[i + n] = endTime[i];
        sort(kp, kp + n + n);
        int m = unique(kp, kp + n + n) - kp;
        for (int i = 0; i < m; ++i)
            mp[kp[i]] = i + 1;
        for (int i = 0; i < n; ++i)
            mp2[endTime[i]].push_back(i);
        f[0] = 0;
        for (int i = 1; i <= m; ++i){
            f[i] = f[i - 1];
            vector<int>& vec = mp2[kp[i - 1]];
            for (int id: vec){
                f[i] = max(f[i], f[mp[startTime[id]]] + profit[id]);
            }
        }
        return f[m];
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
