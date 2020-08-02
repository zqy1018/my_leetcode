#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

template<typename T1, typename T2>
ostream& operator << (ostream& os, const pair<T1, T2>& p){
    os << p.first << " " << p.second << endl;
    return os;
}

inline int lowbit(int x){
    return x & (-x);
}
inline int sgn(int x){
    return (x < 0 ? -1: (x > 0 ? 1: 0));
}

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int ddx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, ddy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


class Solution {
    long long f[100005], g[100005];
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int cur1 = 0, cur2 = 0;
        while (cur1 < n && cur2 < m){
            if (nums1[cur1] < nums2[cur2]){
                f[cur1 + 1] = f[cur1] + nums1[cur1];
                ++cur1;
            }else if (nums1[cur1] > nums2[cur2]){
                g[cur2 + 1] = g[cur2] + nums2[cur2];
                ++cur2;
            }else {
                f[cur1 + 1] = max(f[cur1], g[cur2]) + nums1[cur1];
                g[cur2 + 1] = max(f[cur1], g[cur2]) + nums2[cur2];
                ++cur1;
                ++cur2;
            }
        }
        while (cur1 < n){
            f[cur1 + 1] = f[cur1] + nums1[cur1];
                ++cur1;
        }
        while (cur2 < m){
            g[cur2 + 1] = g[cur2] + nums2[cur2];
                ++cur2;
        }
        return max(f[n], g[m]) % 1000000007;
    }
};
Solution sol;

int main(){

    return 0;
}
