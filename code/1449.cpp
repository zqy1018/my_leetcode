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
    int f[5005], to[5005];
public:
    string largestNumber(vector<int>& cost, int target) {
        string ans;
        memset(f, -1, sizeof(f));
        f[0] = 0;
        for (int i = 1; i <= target; ++i){
            for (int j = 0; j < 9; ++j)
                if (i >= cost[j] && f[i - cost[j]] >= 0){
                    if (f[i] <= f[i - cost[j]] + 1)
                        f[i] = f[i - cost[j]] + 1, to[i] = j;
                }
        }
        if (f[target] <= 0) return string("0");
        int fr = target;
        while (fr > 0 && f[fr] > 0){
            ans.push_back(to[fr] + '0' + 1);
            fr -= cost[to[fr]];
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
