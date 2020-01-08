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
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        k = min(k, n * m);
        vector<vector<int>> ans;
        if (!k) return ans;
        
        auto cmp = [&nums1, &nums2](const pair<int, int>& p1, const pair<int, int>& p2){
            return nums1[p1.first] + nums2[p1.second] > nums1[p2.first] + nums2[p2.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        for (int i = 0; i < n; ++i) 
            pq.push(make_pair(i, 0));
        for (int i = 0; i < k; ++i){
            pair<int, int> pp = pq.top();
            pq.pop();
            ans.push_back(vector<int>{nums1[pp.first], nums2[pp.second]});
            if (pp.second < nums2.size() - 1)
                pq.push(make_pair(pp.first, pp.second + 1));
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
