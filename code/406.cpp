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
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<int> iid(n, 0), pos(n, 0);
        vector<vector<int>> ans(n, vector<int>());
        for (int i = 0; i < n; ++i) iid[i] = pos[i] = i;
        auto cmp = [&people](int v1, int v2){
            if (people[v1][0] == people[v2][0]) 
                return people[v1][1] < people[v2][1];
            return people[v1][0] < people[v2][0];
        };
        sort(iid.begin(), iid.end(), cmp);
        for (int i = 0; i < n; ++i){
            int id = iid[i];
            ans[pos[people[id][1]]].push_back(people[id][0]);
            ans[pos[people[id][1]]].push_back(people[id][1]);
            pos.erase(pos.begin() + people[id][1]);
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
