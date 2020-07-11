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


const int M = 1000000007;
class Solution {
    int cnt[100005];
    inline int modadd(int x, int y){
    return (x + y >= M ? x + y - M: x + y);
}
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        for (int i = 0; i < n; ++i){
            int sum = 0;
            for (int j = i; j < n; ++j)
                sum += nums[j], ++cnt[sum];
        }
        int ansl = 0, ansr = 0;
        --left;
        for (int i = 1; i <= 100000; ++i){
            int used = min(left, cnt[i]);
            ansl = modadd(ansl, 1ll * used * i % M);
            left -= used;
            used = min(right, cnt[i]);
            ansr = modadd(ansr, 1ll * used * i % M);
            right -= used;
        }
        ansr = modadd(ansr, M - ansl);
        return ansr;
    }
};
Solution sol;

int main(){

    return 0;
}
