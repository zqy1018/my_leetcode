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

const int M = 1000000007;
inline int modadd(int x, int y){
    return (x + y >= M ? x + y - M: x + y);
}
int poww(int a, int b){
    int res = 1;
    while (b > 0){
        if (b & 1)
            res = 1ll * res * a % M;
        a = 1ll * a * a % M, b >>= 1;
    }
    return res;
}

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int ddx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, ddy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

class Solution {
    deque<int> dq;
public:
    int getWinner(vector<int>& arr, int k) {
        int maxi = -1;
        for (int x: arr) maxi = max(maxi, x), dq.push_back(x);
        int lst = -1, ls = 0;
        for (; ; ){
            int t = dq.front();
            dq.pop_front();
            if (t == maxi) return maxi;
            if (t > dq.front()){
                int tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
                dq.push_front(t);
                if (lst != t){
                    lst = t, ls = 1;
                }else ++ls;
            }else {
                dq.push_back(t);
                if (lst != dq.front()){
                    lst = dq.front(), ls = 1;
                }else ++ls;
            }
            if (ls == k) return lst;
        }
        return -1;
    }
};
Solution sol;

int main(){

    return 0;
}
