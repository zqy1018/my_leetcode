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
    int f[105][105][105][3];
    char lz[105][105][105][3];
    bool step[105][105][105][3];
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        f[0][0][0][0] = f[0][0][0][1] = f[0][0][0][2] = 0;
        for (int i = 0; i <= a; ++i){
            for (int j = 0; j <= b; ++j){
                for (int k = 0; k <= c; ++k){
                    // use a
                    if (i >= 1){
                        if (f[i - 1][j][k][1] > f[i - 1][j][k][2])
                            f[i][j][k][0] = f[i - 1][j][k][1] + 1, 
                            lz[i][j][k][0] = 1;
                        else
                            f[i][j][k][0] = f[i - 1][j][k][2] + 1, 
                            lz[i][j][k][0] = 2;
                        step[i][j][k][0] = false;    
                    }
                    if (i >= 2){
                        if (f[i - 2][j][k][1] + 2 > f[i][j][k][0])
                            f[i][j][k][0] = f[i - 2][j][k][1] + 2, 
                            lz[i][j][k][0] = 1, step[i][j][k][0] = true; 
                        if (f[i - 2][j][k][2] + 2 > f[i][j][k][0])
                            f[i][j][k][0] = f[i - 2][j][k][2] + 2, 
                            lz[i][j][k][0] = 2, step[i][j][k][0] = true; 
                    }
                    // use b
                    if (j >= 1){
                        if (f[i][j - 1][k][0] > f[i][j - 1][k][2])
                            f[i][j][k][1] = f[i][j - 1][k][0] + 1, 
                            lz[i][j][k][1] = 0;
                        else
                            f[i][j][k][1] = f[i][j - 1][k][2] + 1, 
                            lz[i][j][k][1] = 2;
                        step[i][j][k][1] = false;    
                    }
                    if (j >= 2){
                        if (f[i][j - 2][k][0] + 2 > f[i][j][k][1])
                            f[i][j][k][1] = f[i][j - 2][k][0] + 2, 
                            lz[i][j][k][1] = 0, step[i][j][k][1] = true; 
                        if (f[i][j - 2][k][2] + 2 > f[i][j][k][1])
                            f[i][j][k][1] = f[i][j - 2][k][2] + 2, 
                            lz[i][j][k][1] = 2, step[i][j][k][1] = true; 
                    }
                    // use c
                    if (k >= 1){
                        if (f[i][j][k - 1][0] > f[i][j][k - 1][1])
                            f[i][j][k][2] = f[i][j][k - 1][0] + 1, 
                            lz[i][j][k][2] = 0;
                        else
                            f[i][j][k][2] = f[i][j][k - 1][1] + 1, 
                            lz[i][j][k][2] = 1;
                        step[i][j][k][2] = false;  
                    }
                    if (k >= 2){
                        if (f[i][j][k - 2][0] + 2 > f[i][j][k][2])
                            f[i][j][k][2] = f[i][j][k - 2][0] + 2, 
                            lz[i][j][k][2] = 0, step[i][j][k][2] = true; 
                        if (f[i][j][k - 2][1] + 2 > f[i][j][k][2])
                            f[i][j][k][2] = f[i][j][k - 2][1] + 2, 
                            lz[i][j][k][2] = 1, step[i][j][k][2] = true; 
                    }
                }
            }
        }
        int maxi = -1, maxp = -1;
        for (int i = 0; i < 3; ++i)
            if (f[a][b][c][i] > maxi)
                maxi = f[a][b][c][i], 
                maxp = i;
        while (f[a][b][c][maxp] > 0){
            ans.push_back(maxp + 'a');
            if (step[a][b][c][maxp])
                ans.push_back(maxp + 'a');
            int tmp = lz[a][b][c][maxp];
            if (maxp == 0) a -= 1 + (step[a][b][c][maxp] ? 1: 0);
            if (maxp == 1) b -= 1 + (step[a][b][c][maxp] ? 1: 0);
            if (maxp == 2) c -= 1 + (step[a][b][c][maxp] ? 1: 0);
            maxp = tmp;
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
