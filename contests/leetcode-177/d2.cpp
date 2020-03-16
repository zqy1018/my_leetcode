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

const int num[] = {1, 2, 4, 5, 7, 8};
class Solution {
    int cnt[11], f[11][3], g[11][3][2];
public:
    string largestMultipleOfThree(vector<int>& digits) {
        for (int x: digits)
            ++cnt[x];
        bool only0 = true;
        for (int i = 1; i < 10; ++i)
            if (cnt[i]){
                only0 = false;
                break;
            }
        if (only0){
            return string("0");
        }
        memset(f, -1, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= 6; ++i){
            int nt = num[i - 1];
            for (int j = 0; j <= min(2, cnt[nt]); ++j){
                int p = nt * j % 3;
                int used = j + ((cnt[nt] - j) / 3) * 3;
                for (int k = 0; k < 3; ++k){
                    if (f[i - 1][k] >= 0){
                        int to = (p + k) % 3;
                        if (f[i][to] < f[i - 1][k] + used){
                            f[i][to] = f[i - 1][k] + used;
                            g[i][to][0] = k, g[i][to][1] = used;
                        }else if (f[i][to] == f[i - 1][k] + used && used > g[i][to][1]){
                            f[i][to] = f[i - 1][k] + used;
                            g[i][to][0] = k, g[i][to][1] = used;
                        }
                    }
                }
            }
        }
        // cout << f[6][0] << endl;
        
        string res;
        int cur = 6, curk = 0;

        if (f[cur][curk] < 0){
            for (int i = 9; i > 0; i -= 3){
                for (int j = 0; j < cnt[i]; ++j)
                    res.push_back('0' + i);
            }
            if (res.empty()){
                for (int i = 0; i < min(1, cnt[0]); ++i)
                    res.push_back('0');
            }
            return res;
        }

        for (int i = 0; i < cnt[9]; ++i)
            res.push_back('9');
        for (int i = 0; i < g[cur][curk][1]; ++i)
            res.push_back(num[cur - 1] + '0');
        curk = g[cur][curk][0], --cur;
        for (int i = 0; i < g[cur][curk][1]; ++i)
            res.push_back(num[cur - 1] + '0');
        curk = g[cur][curk][0], --cur;

        for (int i = 0; i < cnt[6]; ++i)
            res.push_back('6');
        for (int i = 0; i < g[cur][curk][1]; ++i)
            res.push_back(num[cur - 1] + '0');
        curk = g[cur][curk][0], --cur;
        for (int i = 0; i < g[cur][curk][1]; ++i)
            res.push_back(num[cur - 1] + '0');
        curk = g[cur][curk][0], --cur;

        for (int i = 0; i < cnt[3]; ++i)
            res.push_back('3');
        for (int i = 0; i < g[cur][curk][1]; ++i)
            res.push_back(num[cur - 1] + '0');
        curk = g[cur][curk][0], --cur;
        for (int i = 0; i < g[cur][curk][1]; ++i)
            res.push_back(num[cur - 1] + '0');
        curk = g[cur][curk][0], --cur;

        for (int i = 0; i < cnt[0]; ++i)
            res.push_back('0');
        return res;
    }
};
Solution sol;
void init(){
    vector<int> vec{2, 2, 2, 1, 1};
    cout << sol.largestMultipleOfThree(vec);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
