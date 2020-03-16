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
    vector<int> ans;
    vector<int> tmp1, tmp2, tmp;
    map<pair<int, int>, bool> mp;
    bool cmp(int i, int j){
        if (i == tmp1.size() || j == tmp2.size())
            return j == tmp2.size();
        if (mp.count(make_pair(i, j)))
            return mp[make_pair(i, j)];
        if (tmp1[i] > tmp2[j])
            return (mp[make_pair(i, j)] = true);
        else if (tmp1[i] < tmp2[j])
            return (mp[make_pair(i, j)] = false);
        else 
            return (mp[make_pair(i, j)] = cmp(i + 1, j + 1));
    }
    void merge(){
        mp.clear();
        int lp = 0, rp = 0, pos = 0;
        int n = tmp1.size(), m = tmp2.size();
        while (lp < n && rp < m){
            if (tmp1[lp] > tmp2[rp]) tmp[pos++] = tmp1[lp++];
            else if (tmp1[lp] < tmp2[rp]) tmp[pos++] = tmp2[rp++];
            else{
                if (cmp(lp, rp)) tmp[pos++] = tmp1[lp++];
                else tmp[pos++] = tmp2[rp++];
            }
        }
        while (lp < n) tmp[pos++] = tmp1[lp++];
        while (rp < m) tmp[pos++] = tmp2[rp++];
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        ans = vector<int>(k, 0);
        tmp = vector<int>(k, 0);
        tmp1.reserve(min(k, n));
        tmp2.reserve(min(k, m));
        for (int t = max(0, k - m); t <= k && t <= n; ++t){
            tmp1.clear();
            tmp2.clear();
            for (int i = 0, left = n - t; i < n; ++i){
                while (left > 0 && !tmp1.empty() && nums1[i] > tmp1.back())
                    --left, tmp1.pop_back();
                tmp1.push_back(nums1[i]);
            }
            for (int i = tmp1.size() - t; i > 0; --i)
                tmp1.pop_back();
            for (int i = 0, left = m - k + t; i < m; ++i){
                while (left > 0 && !tmp2.empty() && nums2[i] > tmp2.back())
                    --left, tmp2.pop_back();
                tmp2.push_back(nums2[i]);
            }
            for (int i = tmp2.size() - k + t; i > 0; --i)
                tmp2.pop_back();
            // cout << tmp1 << tmp2 << endl;
            merge();
            bool flag = false;
            for (int i = 0; i < k; ++i)
                if (tmp[i] != ans[i]){
                    flag = tmp[i] > ans[i];
                    break;
                }
            if (flag) {
                for (int i = 0; i < k; ++i)
                    ans[i] = tmp[i];
            }
        }
        return ans;
    }
};
Solution sol;
void init(){
    vector<int> vec1{3, 4, 6, 5}, vec2{9, 1, 2, 5, 8, 3};
    cout << sol.maxNumber(vec1, vec2, 5) << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
