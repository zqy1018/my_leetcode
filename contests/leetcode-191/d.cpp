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
    long double f[9][25][25][9][9];
    long double C[25][25];
public:
    double getProbability(vector<int>& balls) {
        f[0][0][0][0][0] = 1;
        int n = balls.size();
        int sum = 0;
        for (int x: balls) sum += x;
        int hf = sum >> 1;
        C[0][0] = 1;
        for (int i = 1; i <= hf; ++i){
            C[i][0] = 1;
            for (int j = 1; j <= i; ++j)
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
        // 计算组合数

        for (int i = 1; i <= n; ++i){
            int t = balls[i - 1];
            for (int j = hf; j >= t; --j)
                for (int k = 0; k <= hf; ++k)
                    for (int u = i; u >= 1; --u)
                        for (int v = 0; v <= i; ++v)
                            f[i][j][k][u][v] += f[i - 1][j - t][k][u - 1][v] * C[j][t], 
                            f[i][k][j][v][u] += f[i - 1][k][j - t][v][u - 1] * C[j][t];
            // 这种颜色的球全分到某一半
            for (int b = 1; b < t; ++b)
                for (int j = hf; j >= b; --j)
                    for (int k = hf; k >= t - b; --k)
                        for (int u = i; u >= 1; --u)
                            for (int v = i; v >= 1; --v)
                                f[i][j][k][u][v] += f[i - 1][j - b][k - (t - b)][u - 1][v - 1] *
                                    C[j][b] * C[k][t - b];
            // 这种颜色的球两边都分一点
        }
        long double tot = 0, ans = 0;
        for (int i = 0; i <= n; ++i)
            ans += f[n][hf][hf][i][i];
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                tot += f[n][hf][hf][i][j];
        double aans = ans / (1.0 * tot);
        return aans;
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
