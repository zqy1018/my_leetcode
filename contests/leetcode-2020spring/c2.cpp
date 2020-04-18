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

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec){
    for (auto x: vec)
        os << x << " ";
    os << endl;
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<vector<T>>& vec){
    for (auto& v: vec){
        for (auto x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}

class Solution {
    vector<int> G1[100005], G2[100005], G3[100005];
public:
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        int c = 0, r = 0, h = 0;
        int n = increase.size();
        int m = requirements.size();
        vector<int> ans(m, 0);
        for (int i = 0; i < m; ++i) {
            ans[i] = n + 1;
            G1[requirements[i][0]].push_back(i);
            G2[requirements[i][1]].push_back(i);
            G3[requirements[i][2]].push_back(i);
            if (requirements[i][0] == 0 && 
                requirements[i][1] == 0 &&
                requirements[i][2] == 0)
                ans[i] = 0;
        }
        for (int i = 0; i < n; ++i){
            auto& v = increase[i];
            for (int t = 0; t < v[0]; ++t){
                ++c;
                for (int x: G1[c])  
                    if (c >= requirements[x][0] &&
                        r >= requirements[x][1] &&
                        h >= requirements[x][2])
                        ans[x] = min(ans[x], i + 1);
            }
            for (int t = 0; t < v[1]; ++t){
                ++r;
                for (int x: G2[r])  
                    if (c >= requirements[x][0] &&
                        r >= requirements[x][1] &&
                        h >= requirements[x][2])
                        ans[x] = min(ans[x], i + 1);
            }
            for (int t = 0; t < v[2]; ++t){
                ++h;
                for (int x: G3[h])  
                    if (c >= requirements[x][0] &&
                        r >= requirements[x][1] &&
                        h >= requirements[x][2])
                        ans[x] = min(ans[x], i + 1);
            }
        }
        for (int i = 0; i < m; ++i)
            if (ans[i] == n + 1)
                ans[i] = -1;
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
