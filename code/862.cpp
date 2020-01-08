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
    int shortestSubarray(vector<int>& A, int K) {
        vector<int> sm, id;
        int n = A.size(), ssm = 0;
        sm.push_back(0), id.push_back(0);
        for (int i = 0; i < n; ++i)
            ssm += A[i], sm.push_back(ssm), id.push_back(i + 1); 
        sort(id.begin(), id.end(), [&sm](int i, int j){ return (sm[i] == sm[j] ? i < j: sm[i] < sm[j]); });
        int cur = 0, ans = n + 1;
        set<int> st;
        for (int i = 0; i <= n; ++i) {
            while (cur < i && sm[id[cur]] <= sm[id[i]] - K)
                st.insert(id[cur]), ++cur;
            if (!st.empty()){
                auto iter = st.lower_bound(id[i]);
                if (iter != st.begin()) 
                    --iter, ans = min(ans, id[i] - *iter);
            }
        }
        return ans > n ? -1: ans;
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
