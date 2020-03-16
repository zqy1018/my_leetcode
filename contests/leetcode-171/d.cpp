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

class Solution {
public:
    int dis[305][27][27];
    int dist(int a, int b){
        int r1 = a / 6, c1 = a % 6;
        int r2 = b / 6, c2 = b % 6;
        return abs(r1 - r2) + abs(c1 - c2);
    }
    int minimumDistance(string word) {
        memset(dis, 0x3f, sizeof(dis));
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                dis[0][i][j] = 0;
        int l = word.length();
        for (int i = 0; i < l; ++i){
            int c = word[i] - 'A';
            for (int j = 0; j < 26; ++j)
                for (int k = 0; k < 26; ++k)
                    dis[i + 1][j][c] = min(dis[i + 1][j][c], dis[i][j][k] + dist(c, k)), 
                    dis[i + 1][c][j] = min(dis[i + 1][c][j], dis[i][k][j] + dist(c, k));
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < 26; ++i)    
            for (int j = 0; j < 26; ++j)
                ans = min(ans, dis[l][i][j]);
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
