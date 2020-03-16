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
    priority_queue<pair<int, int> > pq_d;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_u;
    int lazy_d, lazy_u, K;
    bool at[10005];
    void clean(int pos){
        while (!pq_d.empty() && pq_d.top().second + K <= pos)
            pq_d.pop(), --lazy_d;
        while (!pq_u.empty() && pq_u.top().second + K <= pos)
            pq_u.pop(), --lazy_u;
    }
    void maintain(int x, int pos){
        clean(pos);
        int offset = K & 1;
        if (x <= pq_d.top().first) pq_d.push(make_pair(x, pos));
        else pq_u.push(make_pair(x, pos)), at[pos] = true;
        for (; ; ){
            int siz1 = pq_d.size() - lazy_d;
            int siz2 = pq_u.size() - lazy_u + offset;
            if (siz1 > siz2){
                at[pq_d.top().second] = true, 
                pq_u.push(pq_d.top()), pq_d.pop();          // 上移
            }else if (siz1 < siz2){
                at[pq_u.top().second] = false, 
                pq_d.push(pq_u.top()), pq_u.pop();          // 下移
            }else break;
            clean(pos);
        }
    }
    inline void pop(int x, int pos){
        (at[pos] ? ++lazy_u: ++lazy_d);
    }
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        if (k == 1){
            for (int x: nums)
                ans.push_back(x);
            return ans;
        }
        int n = nums.size();
        lazy_d = 0, lazy_u = 0, K = k;
        for (int i = 0; i < k; ++i)
            pq_d.push(make_pair(nums[i], i));
        for (int i = (k >> 1); i > 0; --i)
            pq_u.push(pq_d.top()), 
            at[pq_d.top().second] = true,
            pq_d.pop(); 
        for (int i = k; i < n; ++i){
            if (k & 1) ans.push_back(pq_d.top().first);
            else ans.push_back(0.5 * pq_d.top().first + 0.5 * pq_u.top().first);
            pop(nums[i - k], i - k);
            maintain(nums[i], i);
        }
        if (k & 1) ans.push_back(pq_d.top().first);
        else ans.push_back(0.5 * pq_d.top().first + 0.5 * pq_u.top().first);
        return ans;
    }
};
Solution sol;
void init(){
    vector<int> vec{1,3,-1,-3,5,3,6,7};
    cout << sol.medianSlidingWindow(vec, 3) << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
