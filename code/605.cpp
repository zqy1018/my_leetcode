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
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0, l = flowerbed.size(), left = 0;
        while (i < l && !flowerbed[i])  
            ++i;
        if (i == l) return ((i + 1) >> 1) >= n;
        left += (i >> 1);
        for (; i < l; ) {
            while (i < l && flowerbed[i])
                ++i;
            int j = i;
            while (j < l && !flowerbed[j])
                ++j;
            if (j == l){
                left += (j - i) >> 1;
                return left >= n;
            }else left += (j - i - 1) >> 1;
        }
        return true;
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
