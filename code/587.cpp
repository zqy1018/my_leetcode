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

int st[105], tp;
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& v1, vector<int>&v2){ 
            return (v1[0] == v2[0] ? v1[1] < v2[1]: v1[0] < v2[0]);
        });
        auto cross = [](const pair<int, int>& v1, const pair<int, int>& v2){
            return v1.first * v2.second - v2.first * v1.second;
        };
        auto toleft = [&cross](const vector<int>& v1, const vector<int>& v2, const vector<int>& v3){
            pair<int, int> p1 = make_pair(v3[0] - v1[0], v3[1] - v1[1]);
            pair<int, int> p2 = make_pair(v3[0] - v2[0], v3[1] - v2[1]);
            return cross(p1, p2) >= 0;
        };
        int n = points.size();
        tp = 0;
        for (int i = 0; i < n; ++i){
            while (tp > 1 && !toleft(points[st[tp - 1]], points[st[tp]], points[i]))
                --tp;
            st[++tp] = i;
        } 
        for (int i = n - 2, tmp = tp; i >= 0; --i){
            while (tp > tmp && !toleft(points[st[tp - 1]], points[st[tp]], points[i]))
                --tp;
            st[++tp] = i;
        } 
        if (n > 1) --tp;
        vector<vector<int>> ans;
        for (int i = 1; i <= tp; ++i)
            ans.push_back(points[st[i]]);
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
