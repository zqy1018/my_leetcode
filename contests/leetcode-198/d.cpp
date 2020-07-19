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
    int tmp[55], tmp2[55];
public:
    int closestToTarget(vector<int>& arr, int target) {
        int ans = 1000000000;
        int n = arr.size();
        int tot = 0, cnt = 0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < cnt; ++j)
                tmp[tot++] = tmp2[j] & arr[i];
            tmp[tot++] = arr[i];
            sort(tmp, tmp + tot);
            cnt = 0;
            for (int j = 0; j < tot; ){
                int k = j;
                while (k < tot && tmp[j] == tmp[k])
                    ++k;
                ans = min(ans, abs(tmp[j] - target));
                tmp2[cnt++] = tmp[j];
                j = k;
            }
        }
        return ans;
    }
};
Solution sol;

int main(){

    return 0;
}
