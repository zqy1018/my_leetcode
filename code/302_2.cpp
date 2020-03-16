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
    int minArea(vector<vector<char>>& image, int x, int y) {
        int n = image.size(), m = image[0].size();
        int x1_l = 0, x1_r = x;                     // 上边界
        while (x1_l < x1_r){
            int x1_mid = (x1_l + x1_r) >> 1;
            bool flag = false;
            for (int i = 0; i < m; ++i) 
                if (image[x1_mid][i] == '1'){
                    flag = true;
                    break;
                }
            if (flag) x1_r = x1_mid;
            else x1_l = x1_mid + 1;
        }
        int x2_l = x, x2_r = n - 1;                 // 下边界
        while (x2_l < x2_r){
            int x2_mid = (x2_l + x2_r + 1) >> 1;
            bool flag = false;
            for (int i = 0; i < m; ++i) 
                if (image[x2_mid][i] == '1'){
                    flag = true;
                    break;
                }
            if (flag) x2_l = x2_mid;
            else x2_r = x2_mid - 1;
        }
        int y1_l = 0, y1_r = y;                     // 左边界
        while (y1_l < y1_r){
            int y1_mid = (y1_l + y1_r) >> 1;
            bool flag = false;
            for (int i = 0; i < n; ++i) 
                if (image[i][y1_mid] == '1'){
                    flag = true;
                    break;
                }
            if (flag) y1_r = y1_mid;
            else y1_l = y1_mid + 1;
        }
        int y2_l = y, y2_r = m - 1;                 // 右边界
        while (y2_l < y2_r){
            int y2_mid = (y2_l + y2_r + 1) >> 1;
            bool flag = false;
            for (int i = 0; i < n; ++i) 
                if (image[i][y2_mid] == '1'){
                    flag = true;
                    break;
                }
            if (flag) y2_l = y2_mid;
            else y2_r = y2_mid - 1;
        }
        return (x2_l - x1_l + 1) * (y2_l - y1_l + 1);
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
