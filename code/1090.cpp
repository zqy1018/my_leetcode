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
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> mp;
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        int ans = 0, n = values.size();
        for (int i = 0; i < n; ++i) 
            pq.push(make_pair(values[i], labels[i])), 
            mp[labels[i]] = 0;
        int lim = use_limit * mp.size();
        num_wanted = min(num_wanted, lim);
        for (int i = 0; i < num_wanted; ++i){
            while (!pq.empty() && mp[pq.top().second] == use_limit)
                pq.pop();
            if (pq.empty()) break;
            ans += pq.top().first, 
            ++mp[pq.top().second], pq.pop();
        }
        return ans;
    }
};
Solution sol;
void init(){
    vector<int> v1{9, 8, 8, 7, 6}, v2{0, 0, 0, 1, 1};
    cout << sol.largestValsFromLabels(v1, v2, 3, 1);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
