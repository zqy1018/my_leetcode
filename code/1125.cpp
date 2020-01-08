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

int bv[65], f[2][65550], pos[65550], choice[65550];
class Solution {
public:
    int n, m, ans;
    unordered_map<string, int> mp;
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = req_skills.size(), m = people.size();
        for (int i = 0; i < n; ++i) 
            mp[req_skills[i]] = i;
        for (int i = 0; i < m; ++i){
            bv[i] = 0;
            for (string& s: people[i])
                bv[i] |= (1 << mp[s]);
        }
        memset(f, 0x3f, sizeof(f));
        f[1][0] = 0;
        int lim = (1 << n) - 1;
        for (int i = 0; i < m; ++i){
            int B = (i & 1), B_ = 1 - B;
            for (int j = 0; j <= lim; ++j)
                f[B][j] = f[B_][j];
            for (int j = 0; j <= lim; ++j){
                if (f[B_][j] + 1 < f[B][j | bv[i]])
                    f[B][j | bv[i]] = f[B_][j] + 1, pos[j | bv[i]] = j, choice[j | bv[i]] = i;
            }
        }
        int ans = f[(m - 1) & 1][lim];
        vector<int> aans;
        for (int i = choice[lim], j = lim; j > 0; j = pos[j], i = choice[j])
            aans.push_back(i);
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
