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

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec){
    for (auto x: vec)
        os << x << " ";
    os << endl;
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<vector<T>>& vec){
    for (auto& v: vec){
        for (auto x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}
class Solution {
    priority_queue<int, vector<int>, greater<int> > pq;
    int id[100005];
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        for (int i = 0; i < n; ++i)
            id[i]    = i;
        sort(id, id + n, [&](int i, int j){
            return efficiency[i] > efficiency[j];
        });
        long long sm = 0, ans = 0;
        for (int i = 0; i < k; ++i){
            pq.push(speed[id[i]]), sm += 1ll * speed[id[i]];
        }
        for (int i = k; i < n; ++i){
            ans = max(ans, sm * efficiency[id[i - 1]]);
            sm += 1ll * speed[id[i]];
            pq.push(speed[id[i]]);
            sm -= pq.top();
            pq.pop();
        }
        ans = max(ans, sm * efficiency[id[n - 1]]);
        return ans % 1000000007;
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
