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
    priority_queue<int> pq;
    pair<double, int> pp[10005];
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size();
        for (int i = 0; i < n; ++i)
            pp[i].first = 1.0 * wage[i] / quality[i], 
            pp[i].second = i;
        sort(pp, pp + n);
        int sum = 0;
        for (int i = 0; i < K; ++i)
            pq.push(quality[pp[i].second]), 
            sum += quality[pp[i].second];
        double ans = 1e10;
        for (int i = K; i < n; ++i){
            ans = min(ans, pp[i - 1].first * sum);
            pq.push(quality[pp[i].second]), sum += quality[pp[i].second];
            sum -= pq.top(), pq.pop();
        }
        ans = min(ans, pp[n - 1].first * sum);
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
