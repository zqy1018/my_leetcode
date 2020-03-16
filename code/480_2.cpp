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
    multiset<int> st_d, st_u;
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        if (k == 1){
            for (int x: nums)
                ans.push_back(x);
            return ans;
        }
        int n = nums.size();
        for (int i = 0; i < k; ++i)
            st_d.insert(nums[i]);
        for (int i = (k >> 1); i > 0; --i){
            auto p = st_d.end();
            --p;
            st_u.insert(*p), st_d.erase(p);
        }
        for (int i = k; i < n; ++i){
            auto p1 = st_d.end(), p2 = st_u.begin();
            --p1;
            int dd = *p1, uu = *p2;
            if (k & 1) ans.push_back(dd);
            else ans.push_back(0.5 * dd + 0.5 * uu);
            if (nums[i - k] <= dd) {
                st_d.erase(st_d.find(nums[i - k]));
                if (nums[i] < uu) st_d.insert(nums[i]);
                else st_u.erase(p2), st_d.insert(uu), st_u.insert(nums[i]);
            }else {
                st_u.erase(st_u.find(nums[i - k]));
                if (nums[i] > dd) st_u.insert(nums[i]);
                else st_d.erase(p1), st_u.insert(dd), st_d.insert(nums[i]);
            }
        }
        auto p1 = st_d.end(), p2 = st_u.begin();
        --p1;
        int dd = *p1, uu = *p2;
        if (k & 1) ans.push_back(dd);
        else ans.push_back(0.5 * dd + 0.5 * uu);
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
