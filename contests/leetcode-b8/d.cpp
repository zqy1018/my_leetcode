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

int mb[105][105];
class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        if (!maxOnes) return 0;
        int c1 = width % sideLength, c2 = height % sideLength;
        int c3 = width / sideLength, c4 = height / sideLength;
        int ans = 0;
        {
        memset(mb, 0, sizeof(mb));
        int tot = maxOnes;
        for (int k = 0; k < c1 && tot; ++k)
            for (int l = 0; l < c2 && tot; ++l)
                mb[k][l] = 1, --tot;
        for (int k = c1; k < sideLength && tot; ++k)
            for (int l = 0; l < c2 && tot; ++l)
                mb[k][l] = 1, --tot;
        for (int k = 0; k < c1 && tot; ++k)
            for (int l = c2; l < sideLength && tot; ++l)
                mb[k][l] = 1, --tot;
        for (int k = c1; k < sideLength && tot; ++k)
            for (int l = c2; l < sideLength && tot; ++l)
                mb[k][l] = 1, --tot;
        int cnt = maxOnes * (width / sideLength) * (height / sideLength);
        for (int i = 0; i < c1; ++i)
            for (int j = 0; j < sideLength; ++j)
                cnt += mb[i][j] * c4;
        for (int i = 0; i < sideLength; ++i)
            for (int j = 0; j < c2; ++j)
                cnt += mb[i][j] * c3;
        for (int i = 0; i < c1; ++i)    
            for (int j = 0; j < c2; ++j)
                cnt += mb[i][j];
        ans = max(cnt, ans);
        }
        {
        memset(mb, 0, sizeof(mb));
        int tot = maxOnes;
        for (int k = 0; k < c1 && tot; ++k)
            for (int l = 0; l < c2 && tot; ++l)
                mb[k][l] = 1, --tot;
        for (int k = 0; k < c1 && tot; ++k)
            for (int l = c2; l < sideLength && tot; ++l)
                mb[k][l] = 1, --tot;
        for (int k = c1; k < sideLength && tot; ++k)
            for (int l = 0; l < c2 && tot; ++l)
                mb[k][l] = 1, --tot;
        for (int k = c1; k < sideLength && tot; ++k)
            for (int l = c2; l < sideLength && tot; ++l)
                mb[k][l] = 1, --tot;
        int cnt = maxOnes * (width / sideLength) * (height / sideLength);
        for (int i = 0; i < c1; ++i)
            for (int j = 0; j < sideLength; ++j)
                cnt += mb[i][j] * c4;
        for (int i = 0; i < sideLength; ++i)
            for (int j = 0; j < c2; ++j)
                cnt += mb[i][j] * c3;
        for (int i = 0; i < c1; ++i)    
            for (int j = 0; j < c2; ++j)
                cnt += mb[i][j];
        ans = max(cnt, ans);
        }
        return ans;
    }
};
Solution sol;
void init(){
    cout << sol.maximumNumberOfOnes(8, 54, 7, 27);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
