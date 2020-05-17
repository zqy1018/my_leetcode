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
    inline int sqr(int x){
        return x * x;
    }
    inline int count(double rx, double ry, vector<vector<int>>& points, double r){
        int cnt = 0;
        for (auto& v: points){
            double dis = (v[0] - rx) * (v[0] - rx) + (v[1] - ry) * (v[1] - ry);
            dis = sqrt(dis);
            if (dis < r + 1e-7)
                ++cnt;
        }
        return cnt;
    }
public:
    int numPoints(vector<vector<int>>& points, int r) {
        int n = points.size();
        int ans = (n > 0 ? 1: 0);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j){
                int dis = sqr(points[i][0] - points[j][0]) + sqr(points[i][1] - points[j][1]);
                if (dis == 0) continue;
                if (dis > 4 * r * r) continue;
                double dd = sqrt(r * r - 0.25 * dis);
                double midx = 0.5 * (points[i][0] + points[j][0]);
                double midy = 0.5 * (points[i][1] + points[j][1]);
                if (points[i][0] == points[j][0]){
                    // shuzhi]
                    double rx = points[i][0] - dd, ry = midy;
                    ans = max(ans, count(rx, ry, points, r));
                    rx = points[i][0] + dd;
                    ans = max(ans, count(rx, ry, points, r));
                }else if (points[i][1] == points[j][1]){
                    // shuipintg
                    double rx = midx, ry = points[i][1] - dd;
                    ans = max(ans, count(rx, ry, points, r));
                    ry = points[i][1] + dd;
                    ans = max(ans, count(rx, ry, points, r));
                }else {
                    int pa = points[i][0], pb = points[i][1];
                    int pc = points[j][0], pd = points[j][1];
                    int sub1 = pa - pc, sub2 = pb - pd;
                    int subq1 = sqr(sub1), subq2 = sqr(sub2);
                    int rr = 4 * r * r;

                    double fm = 2.0 * sqrt(subq1 + subq2);
                    double fz = sqrt(rr - subq1 - subq2);

                    double rx1 = midx + (1.0 * sub2 * fz / fm), ry1 = midy - (1.0 * sub1 * fz / fm);
                    double rx2 = midx - (1.0 * sub2 * fz / fm), ry2 = midy + (1.0 * sub1 * fz / fm);
                    ans = max(ans, count(rx1, ry1, points, r));
                    ans = max(ans, count(rx2, ry2, points, r));
                }
            }
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
