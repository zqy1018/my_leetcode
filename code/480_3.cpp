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
    priority_queue<int> pq_d;                           // K 是奇数时，认为下堆多一个数
    priority_queue<int, vector<int>, greater<int>> pq_u;
    unordered_map<int, int> mp;
    int balance, K;                 // balance：下堆相较上堆的偏差程度
    void clean(){
        while (!pq_d.empty() && mp[pq_d.top()])
            --mp[pq_d.top()], pq_d.pop();
        while (!pq_u.empty() && mp[pq_u.top()])
            --mp[pq_u.top()], pq_u.pop();
    }
    void maintain(int x){
        if (x <= pq_d.top()) pq_d.push(x), ++balance;
        else pq_u.push(x), --balance;
        clean();
        if (!balance) return ;
        if (balance > 0){
            pq_u.push(pq_d.top()), pq_d.pop();          // 上移
        }else {
            pq_d.push(pq_u.top()), pq_u.pop();          // 下移
        }
        balance = 0;
        clean();
    }
    inline void pop(int x){
        if (x == pq_d.top()) pq_d.pop(), --balance;
        else {
            ++mp[x];
            balance += (x < pq_d.top() ? -1: 1);
        }
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
        balance = 0, K = k;
        // 初始化过程
        for (int i = 0; i < k; ++i)
            pq_d.push(nums[i]);
        for (int i = (k >> 1); i > 0; --i)
            pq_u.push(pq_d.top()), pq_d.pop(); 
        for (int i = k; i < n; ++i){
            if (k & 1) ans.push_back(pq_d.top());
            else ans.push_back(0.5 * pq_d.top() + 0.5 * pq_u.top());
            pop(nums[i - k]);
            maintain(nums[i]);
        }
        if (k & 1) ans.push_back(pq_d.top());
        else ans.push_back(0.5 * pq_d.top() + 0.5 * pq_u.top());
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
