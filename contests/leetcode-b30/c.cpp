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

const int M = 1000000007;
inline int lowbit(int x){
    return x & (-x);
}
inline int modadd(int x, int y){
    return (x + y >= M ? x + y - M: x + y);
}
inline int sgn(int x){
    return (x < 0 ? -1: (x > 0 ? 1: 0));
}

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int ddx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, ddy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n <= 3) return 0;
        int ans = INT_MAX;
        ans = min(ans, nums[n - 4] - nums[0]);
        ans = min(ans, nums[n - 3] - nums[1]);
        ans = min(ans, nums[n - 2] - nums[2]);
        ans = min(ans, nums[n - 1] - nums[3]);
        return ans;
    }
};
Solution sol;

int main(){

    return 0;
}
