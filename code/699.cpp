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

ostream& operator << (ostream& os, const vector<int>& vec){
    for (int x: vec)
        os << x << " ";
    os << endl;
}

ostream& operator << (ostream& os, const vector<vector<int>>& vec){
    for (auto& v: vec){
        for (int x: v)
            os << x << " ";
        os << endl;
    }
}

class Solution {
    vector<int> h, ans;
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        h.push_back(positions[0][1]);
        ans.push_back(positions[0][1]);
        for (int i = 1; i < n; ++i){
            int hh = 0;
            for (int j = 0; j < i; ++j){
                if (positions[j][0] + positions[j][1] <= positions[i][0] ||
                    positions[j][0] >= positions[i][0] + positions[i][1])
                    continue;
                hh = max(hh, h[j]);
            }
            h.push_back(hh + positions[i][1]);
            ans.push_back(max(ans.back(), h.back()));
        }
        return ans;
    }
};
Solution sol;
void init(){
    vector<vector<int>> vec{{1, 2}, {2, 3}, {6, 1}};
    cout << sol.fallingSquares(vec) << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
