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
    priority_queue<int> pq;
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int n = Profits.size();
        k = min(k, n);
        vector<int> id(n, 0);
        for (int i = 0; i < n; ++i) id[i] = i;
        sort(id.begin(), id.end(), [&Capital](int i, int j){ return Capital[i] < Capital[j]; });
        int cur = 0;
        while (cur < n && Capital[id[cur]] <= W)
            pq.push(Profits[id[cur]]), ++cur;
        for (int i = 0; i < k && !pq.empty(); ++i){
            W += pq.top(), pq.pop();
            while (cur < n && Capital[id[cur]] <= W)
                pq.push(Profits[id[cur]]), ++cur;
        }
        return W;
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
