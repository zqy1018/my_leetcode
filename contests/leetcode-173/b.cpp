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
    int tmp[100005];
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        int n = restaurants.size();
        int tot = 0;
        for (int i = 0; i < n; ++i){
            if (veganFriendly){
                if (restaurants[i][2]){
                    if (restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance)
                        tmp[tot++] = i;
                }
            }else {
                if (restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance)
                        tmp[tot++] = i;
            }
        }
        sort(tmp, tmp + tot, [&restaurants](int i, int j){
            if (restaurants[i][1] == restaurants[j][1]) return  restaurants[i][0] > restaurants[j][0];
            return  restaurants[i][1] > restaurants[j][1];
        });
        vector<int> ans;
        for (int i = 0; i < tot; ++i)
            ans.push_back(restaurants[tmp[i]][0]);
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
