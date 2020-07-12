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
    inline double sqr(double a){
        return a * a;
    }
    double calc(double a, double b, vector<vector<int>>& positions){
        double ans = 0;
        for (auto& v: positions)
            ans += sqrt(sqr(a - v[0]) + sqr(b - v[1]));
        return ans;
    }
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        double T = 10000;
        double x = positions[0][0], y = positions[0][1];
        double curans = calc(x, y, positions);
        srand(1145);
    	while(T > 1e-8){
            double rat1 = (2.0 * rand() - RAND_MAX) / (0.02 * RAND_MAX);
            double rat2 = (2.0 * rand() - RAND_MAX) / (0.02 * RAND_MAX);
            double xx = x + rat1 * T;
            double yy = y + rat2 * T;
            double aans = calc(xx, yy, positions);
            double delta = aans - curans;
            if (aans < curans || rand() % 10000 < T)
                x = xx, y = yy, curans = aans;
            T *= 0.998;
    	}
        return curans;
    }
};
Solution sol;

int main(){

    return 0;
}
