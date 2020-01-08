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
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int k = 0;
        while (num_people * num_people * (k - 1) * k / 2 + num_people * (num_people + 1) * k / 2
            <= candies)
            ++k;
        --k;
        candies -= num_people * num_people * (k - 1) * k / 2 + num_people * (num_people + 1) * k / 2;
        for (int i = 0; i < num_people; ++i)
            ans[i] = num_people * k * (k - 1) / 2 + k * (i + 1);
        for (int i = 0; i < num_people && candies; ++i){
            int t = min(candies, k * num_people + i + 1);
            ans[i] += t;
            candies -= t;
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
