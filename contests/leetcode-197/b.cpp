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


inline int sgn(int x){
    return (x < 0 ? -1: (x > 0 ? 1: 0));
}

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int ddx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, ddy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    const int M = 1000000007;
class Solution {
inline int modadd(int x, int y){
    return (x + y >= M ? x + y - M: x + y);
}
public:
    int numSub(string s) {
        int l = s.length();
        long long ans = 0;
        for (int i = 0; i < l; ){
            int j = i;
            while (j < l && s[i] == s[j])
                ++j;
            if (s[i] == '1'){
                long long d = j - i;
                long long t = 1ll * d * (d + 1) / 2ll;
                ans += t;
            }
            i = j;
        }
        return ans % M;
    }
};
Solution sol;

int main(){

    return 0;
}
